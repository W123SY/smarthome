<template>
	<view class="container">
		<view class="text-center ">
			<image class="avatar" src="/static/image/yonghu.png" mode=""></image>
		</view>
		<view class="list-cell b-b m-t" @click="navTo('个人资料')" hover-class="cell-hover" :hover-stay-time="50">
			<text class="cell-tit">个人资料</text>
			<text class="cell-more yticon icon-you"></text>
		</view>
		
		<view class="list-cell" @click="shiming()" hover-class="cell-hover" :hover-stay-time="50">
			<text class="cell-tit">实名认证</text>
			<text class="cell-more yticon icon-you"></text>
		</view>
		
		<view class="list-cell m-t">
			<text class="cell-tit">消息推送</text>
			<switch checked color="#fa436a" @change="switchChange" />
		</view>
		<view class="list-cell m-t b-b" @click="clear()" hover-class="cell-hover" :hover-stay-time="50">
			<text class="cell-tit">清除缓存</text>
			<text class="cell-more yticon icon-you"></text>
		</view>
		
		<view class="list-cell b-b" @click="navTo('关于Dcloud')" hover-class="cell-hover" :hover-stay-time="50">
			<text class="cell-tit">关于我们</text>
			<text class="cell-more yticon icon-you"></text>
		</view>
		<view class="list-cell">
			<text class="cell-tit">检查更新</text>
			<text class="cell-tip">当前版本 1.0.3</text>
			<text class="cell-more yticon icon-you"></text>
		</view>
		<view class="list-cell log-out-btn" @click="toLogout()">
			<text class="cell-tit">退出登录</text>
		</view>
		 <image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
	</view>
</template>

<script>
	import {  
	    mapMutations  
	} from 'vuex';
	export default {
		data() {
			return {
				
			};
		},
		methods:{
			shiming(){
				uni.navigateTo({
				                   
				                    url: "/pages/shiming/shiming"
				
				                })
			},
			clear(){
							uni.showModal({
								title:'提示',
								content:'是否要清除所有缓存？',
								cancelText:'不清除',
								confirmText:'清除',
								confirmColor:'#FF4A6A',
								success: (res) => {
									if(res.confirm){
										// 清除所有本地缓存
										// uni.clearStorage()
										// 更新最新的缓存信息
										// this.getStorageInfo()
										// 提示一下
										uni.showToast({
											title:'清除成功',
											icon:'none'
										})
									}
								}
							})
							},
			// ...mapMutations(['logout']),

			// navTo(url){
			// 	this.$api.msg(`跳转到${url}`);
			// },
			//退出登录
			toLogout(){
				uni.showModal({
				    content: '确定要退出登录么',
				    success: (res)=>{
				    
					if (res.confirm) {
												// this.$store.commit('logout')
												uni.navigateBack({
													delta:100
												})
												uni.showToast({
													title:"退出登录成功",
													icon:'none'
												})
				    	}
				    }
				});
			},
			//switch
			switchChange(e){
				let statusTip = e.detail.value ? '打开': '关闭';
				this.$api.msg(`${statusTip}消息推送`);
			},

		}
	}
</script>

<style lang='scss'>
	.avatar{
		width: 100px;
		height: 100px;
		top:10px;
		display: block;
		margin: 0 auto;
		padding: 10px;
	}
	page{
		background:  #f8f8f8;
	}
	.list-cell{
		display:flex;
		align-items:baseline;
		padding: 20upx 30upx;
		line-height:60upx;
		position:relative;
		background: #fff;
		justify-content: center;
		&.log-out-btn{
			margin-top: 40upx;
			.cell-tit{
				color: #007aff;
				text-align: center;
				margin-right: 0;
			}
		}
		&.cell-hover{
			background:#fafafa;
		}
		&.b-b:after{
			left: 30upx;
		}
		&.m-t{
			margin-top: 16upx; 
		}
		.cell-more{
			align-self: baseline;
			font-size:32upx;
			color:#909399;
			margin-left:10upx;
		}
		.cell-tit{
			flex: 1;
			font-size: 30upx;
			color: #303133;
			margin-right:10upx;
		}
		.cell-tip{
			font-size: 28upx;
			color:  #909399;
		}
		.switch{
			transform: translateX(16upx) scale(.84);
		}
	}
	.mensuo-img{
			
			position: fixed;
			    width: 100%;
			    height: 100%;
			    top: 0;
			    left: 0;
			    z-index: -1;
		}
</style>

