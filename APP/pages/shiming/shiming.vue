<template>
	<view class="content">
		
		<view class="uni-common-mt">
			 <view class="uni-form-item uni-column option">
				<view class="title msg-left">姓名：</view>
				<input class="uni-input msg-right" placeholder="请输入真实姓名" v-model="name"/>
			</view>
			
			<view class="uni-form-item uni-column option">
				<view class="title msg-left">身份证号码：</view>
				<input class="uni-input msg-right" type="number" placeholder="请输入身份证号码" v-model="IdNumber"/>
			</view>
			<view class="uni-form-item uni-column img">
				<view class="title">上传身份证:</view>
				<image class="img" src="/static/images//shenfenzheng.png" @tap="scan()"></image>
			</view>
		</view>
		
		<view class="btn">
			<button style="background-color:#5ab5fa" @click="getIDCard()">点击认证身份信息</button>
		</view>
		 <image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
	</view>
</template>
 
<script>
	var that;
	const card = uni.requireNativePlugin('DC-CardRecognize');
	export default{
		data() {
			return {
				title: 'input',
				focus: false,
				name: "",
				IdNumber:"",
				src:"../../../../static/me/photo.png",
				httpUrl:"https://aip.baidubce.com/rest/2.0/ocr/v1/general?access_token=",
				imageBase64Str:"",
				access_token:""
			}
		},
		onLoad() {
			that=this;
			//token验证
			this.getAccess_token();
		},
		methods: {
			getAccess_token(){
				var accessToken= that.cache("accessToken",null,null);
				console.log(accessToken)
				if(!accessToken){
					uni.request({
						method: 'POST',
						header: {
							'Content-Type': 'application/x-www-form-urlencoded'
						},
						url: "https://aip.baidubce.com/oauth/2.0/token",
						data:{
							grant_type:"client_credentials",
							client_id:this.APIKey,
							client_secret:this.SecretKey
						},
						success: function(res) {
							console.log(res.data.access_token);
							//uni.setStorageSync("Baidu",res.data);
							that.access_token=res.data.access_token;
							that.cache("accessToken",res.data.access_token,null);
						}
					})
				}else{
					that.access_token=accessToken;
				}
 
			},
			//缓存,默认有效期28天
			 cache:function(key, value, seconds) {
				var timestamp = Date.parse(new Date()) / 1000
				 console.log(timestamp+"==="+key)
				if (key && value === null) {
					//删除缓存
					//获取缓存
					var val = uni.getStorageSync(key);
					var tmp = val.split("|")
					if (!tmp[1] || timestamp >= tmp[1]) {
						console.log("key已失效")
						uni.removeStorageSync(key)
						return ""
					} else {
						console.log("key未失效")
						return tmp[0]
					}
				} else if (key && value) {
					//设置缓存
					if (!seconds) {
						var expire = timestamp + (3600 * 24 * 28)
					}else{
						var expire = timestamp + seconds
					}
					value = value + "|" + expire
					uni.setStorageSync(key, value);
				} else {
					console.log("key不能空")
				}
			},
			getIDCard() {
				var flag=this.verifyData();
				
				if(flag){
					console.log("==")
					//百度名片识别接口处理开始
					uni.showLoading({
						mask: true,
						title: "识别中，请等待"
					});
					uni.request({
						url: "https://aip.baidubce.com/rest/2.0/ocr/v1/idcard?access_token="+that.access_token,
						method: 'POST',
						header: {
							'Content-Type': 'application/x-www-form-urlencoded'
						},
						data: {
							image: that.imageBase64Str,
							id_card_side:"front"
						},
						success: function(res) {
							console.log(res);
							var IdCard=res.data.words_result.公民身份号码.words;
							var userName=res.data.words_result.姓名.words;
							console.log(res.data.words_result.公民身份号码.words)
							if(IdCard==that.IdNumber&&userName==that.name){
								console.log("身份验证成功");
								uni.showToast({
									icon: 'success',
									title: '身份验证成功'
								});
							}else{
								uni.showToast({
									icon: 'none',
									title: '身份信息有误请审核信息'
								});
							}
						},
						complete() { 
							uni.hideLoading();
						}
					})
				}
			
			},
			//校验输入的数据
			verifyData() {
				var flag = true;
				if (!this.name) {
					flag = false;
					uni.showToast({
						icon: 'none',
						title: '姓名不能为空'
					});
					return false;
				}
				if (!this.IdNumber) {
					flag = false;
					uni.showToast({
						icon: 'none',
						title: '身份证号不能为空'
					});
					return false;
				}
				var re15 = /^[1-9]\d{7}((0\d)|(1[0-2]))(([0|1|2]\d)|3[0-1])\d{3}$/;
				var re18 = /^[1-9]\d{5}[1-9]\d{3}((0\d)|(1[0-2]))(([0|1|2]\d)|3[0-1])\d{4}$/;
				var res = (re15.test(this.IdNumber) || re18.test(this.IdNumber));  
				if(res==false){
					flag = false;
				    uni.showToast({
				    	icon: 'none',
				    	title: '身份证号填写有误'
				    }); 
				    return false;  
				} 
				if(!this.imageBase64Str){
					flag = false;
					uni.showToast({
						icon: 'none',
						title: '请上传身份证含照片一面'
					}); 
					return false;  
				}
				return flag;
 
				},
			scan() {
				var me = this;
				uni.chooseImage({
					count: 1,
					sizeType: ['compressed'],
					sourceType: ['album', 'camera'],
					success: function(res) {
						var tempFilePath = res.tempFilePaths[0];
						me.tempFile = tempFilePath;
						plus.io.resolveLocalFileSystemURL(me.tempFile, function(entry) {
							entry.file(function(file) {
								var fileReader = new plus.io.FileReader();
								fileReader.readAsDataURL(file);
								fileReader.onloadend = function(evt) {
									//console.log("=="+evt.target.result);
									that.imageBase64Str = evt.target.result.split(",")[1];
									that.src=evt.target.result;
								}
							})
						})
						
					}
				})
			}
		}
	}
</script>
 
<style>
	.mensuo-img{
			
			position: fixed;
			    width: 100%;
			    height: 100%;
			    top: 0;
			    left: 0;
			    z-index: -1;
		}
	.option{
		display: flex;
		margin-top: 4%;
		margin-left: 30upx;
		padding-bottom: 30upx;
		border-bottom: #333333 solid 0.5upx;
	}
	.msg-left {
		flex: 5;
		display: flex;
		justify-content: flex-start;
		align-items: center;
	}
	.msg-right {
		flex: 4;
		display: flex;
		justify-content: center;
		text-align: center;
		margin-right: 15upx;
		border-bottom: #000000 solid 0.5upx;
	}
	.img {
	;
		display: flex;
		margin-top: 4%;
		margin-left: 30upx;
		padding-bottom: 30upx;
	}
	.img image {
		justify-content: center;
		margin-top: 8%;
		width: 300upx;
		height: 300upx;
	}
	.btn{
		margin: 0 10%;
		padding: 5px;
	}
</style>