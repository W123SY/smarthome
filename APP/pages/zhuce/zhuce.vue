
<template>
	<view class="content">
		<!-- <view class="login_img"><image mode="aspectFill" src="/static/image/iamhe.png"></image></view> -->
		
		<view class="login_from">
			
			<view class="login_from_input">
				<view class="login_from_name">手机号</view>
				<view class="login_from_fun"><input type="text" placeholder="请输入手机号码"></view>
			</view>

			<view class="login_from_input">
				<view class="login_from_name">密码</view>
				<view class="login_from_fun"><input type="digit" password="true" placeholder="请输入登录密码"></view>
			</view>

			<view class="login_from_input">
				<view class="login_from_name">验证码</view>
				<view class="login_from_fun">
					<input style="width: 40%; text-align: left" type="digit" maxlength="6" placeholder="验证码">
					<label class="regFrom_tom_yzlabel" :style="{ color : QzyzmStare?'#cccccc':'#2ebbfe'}" @click="Qzyzm">{{Qztime}}{{Qztext}}</label>
				</view>
			</view>

			<view class="login_from_input">
				<view class="login_from_name">邀请码</view>
				<view class="login_from_fun">
					<input type="text" placeholder="请输入邀请码">
					<label class="cuIcon-scan cuicon"></label>
				</view>
			</view>
			
			
			<!-- <view class="login_from_input" @tap="handleTap('picker3')">
				<view class="login_from_name">所属地区</view>
				<view class="login_from_fun">
					<input type="text" disabled="true" :value="label3" style="text-align: right;">
					<label class="cuIcon-right cuicon"></label>
				</view>
				<lb-picker ref="picker3" v-model="value3" mode="multiSelector" :list="list1" :level="3"
					:dataset="{ name: 'label3' }" @change="handleChange" @confirm="handleConfirm" @cancel="handleCancel">
				</lb-picker>
			</view> -->
			<!-- 地区选择 end	 -->
			<view class="login_from_dl">
				<button @click="fanhui()">返回</button>
			</view>
			<view class="login_from_dl">
				<button @click="denglu">注册</button>
			</view>
			
			<view class="logo_xieyi">
				<label @click="moutcl" :class="gouxSta?'cuIcon-squarecheckfill':'cuIcon-square'"></label>
				<view class="logo_text">请勾选并阅读<text>《注册协议》</text>及<text>《隐私协议》</text></view>
			</view>
			
		</view>
		
	</view>
</template>
<script>
	
	



   export default {

   data(){
     return {
		 
		// 地区选择 start 
			// value3: [],
			// label3: '',
			// list1: areaData,
		// 地区选择 end 
		gouxSta:false,
		 Qztime:'',
		 QzyzmStare:false,
		 Qztext:'获取验证码'
		 
	}
	   },
    onLoad(){
     },
    methods: {
		fanhui(){
			uni.redirectTo({
			            //关闭当前页面，跳转到应用内的某个页面。
			            url:'/pages/massage/massage'
			        });
		},
		moutcl(){
			if( this.gouxSta == false){
				this.gouxSta = true
			}else{
				this.gouxSta = false
			}
		},
		
		denglu(){
			if( this.gouxSta == false){
				uni.showToast({
					"title":"请阅读并勾选用户协议",
					"icon":'none'
				})				
			}else{
				uni.showToast({
					"title":"账号不存在",
					"icon":'none'
				})
			}		
		},
		
		
		Qzyzm(){
					var num = 60;
					if( this.QzyzmStare == false){
						this.Qztime ='60';
						this.Qztext = 's后获取';
						this.QzyzmStare = true;
						var interval = setInterval(() =>{
								--this.Qztime
							},1000)
						setTimeout(()=>{
							clearInterval(interval)
							this.Qztext = '获取验证码'
							this.Qztime = ''
							this.QzyzmStare = false
						},60000)				
					}
				}	,

		
		
		// 所属地区选择 start
		handleTap(picker) { this.$refs[picker].show() },
		handleChange(e) { console.log('change::', e) },
		handleConfirm(e) { console.log('confirm::', e)
			if (e) {
				const name = e.dataset.name
				const label = e.item.map(m => m.label).join('-')
				if (name && label) {
					this[name] = label
				}
			}
		},
		handleCancel(e) { console.log('cancel::', e) }	
		// 所属地区选择 end
     }
 }
</script>
<style>
	
	page{ background: #fff; }
	
	.login_img{ width: 100%; height: auto; margin-top: 90upx; }
	.login_img image{ width: 170upx; height: 170upx; display: block; margin: 0px auto; border-radius: 50%; }
	
	.login_from{ width: 100%; height: auto; box-sizing: border-box; padding: 20upx 8%; }
	
	.login_from_input{ width: 100%; height:auto; display: flex; flex-direction: row; justify-content: space-between; align-items: center; border-bottom: 1px #eee solid; padding: 40upx 0px; margin: 0px auto;  } 
	
	.login_from_name{ width: 20%; }
	.login_from_fun{ width: 80%; display: flex; flex-direction: row; justify-content: flex-end; align-items: center;  }
	.login_from_fun input{ width: 100%; text-align: left; font-size: 14px;  }
	
	
	.login_from_dl{ width: 100%; height: 50px; line-height: 50px; margin-top: 50upx;   }
	.login_from_dl button{ width: 80%; height: 50px; line-height: 50px; background: #FF3B00; color: #fff; border-radius: 50px; }
	
	.logo_xieyi{ width: 100%; height: 40px; line-height: 40px; display: flex; flex-direction: row; margin-top: 30upx; align-items: center; color: #444; font-size: 14px; justify-content: center; }
	.logo_xieyi label{ font-size: 18px; margin-right: 1%; display: block; width: 15px; height: 15px; }
	
	.cuIcon-squarecheckfill{ color: #FF3B00; }
	.logo_text text{ color: #FF3B00; }
	
	.getyzm{ width: 60%; display: flex; flex-direction: row; justify-content: flex-end; color: #FF3B00; }
	.cuicon{ font-size: 18px; }  
	
	.regFrom_tom_yzlabel{ width: 60%; text-align: right; }
	.cuIcon-squarecheckfill{ background: #FF3B00; position: relative; border: 2px #ccc solid; box-sizing: border-box; border-radius: 3px; }
	.cuIcon-square{ background: #fff; border: 2px #ccc solid; box-sizing: border-box; border-radius: 3px; }
	
</style>



