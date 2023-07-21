<template>
	<view class="content">
		
		<view class="userback">
			<img src="../../static/image/denglujiemian.png">
			
		</view>
		<view class="cu-list menu-avatar">			
			<view class="cu-item">								
				<view class="content">
					<input  prefixIcon="person" placeholder="请输入登录用户名">
					</input>
					
					</view>
					
					<view class="content1">
		          <!-- input type="text" placeholder="退款密码" :password="openPassword"/>
			      <!-- <view :class="[!openPassword ? 'psd-eye-active' : 'psd-eye']" @click="changePassword"></view> -->
					      <!-- <image class="psd-eye" :src="psdUrl"  mode="aspectFill" @click="changePassword"></image>-->
						  
					 <input type="text" :password="showPassword" placeholder="请输入密码"></input>
					<view @click="showPwd" class="pwdmodel"><image :src="pwdIcon" class="pwdImg"></image></view>
					</view >														
			
			</view>	
		</view>		
		<view class="btn-row">
			<button style="background-color:#87CEFA"  @click="denglu()">登录</button>
			
			
		</view>
		<view class="btn-row1">
			<button style="background-color:#87CEFA"  @click="zhuce()">注册</button>
			
			
		</view>
	</view>
</template>
<script>
	export default {
		data() {
			return {
				                showPassword: true,
								
				                psdUrl:'/static/images/icon_turn.png'
			}
		},
		methods: {
			 showPwd: function() {
			                         this.showPassword = !this.showPassword;
			 			 
			 			if(this.showPassword == true){
			 				this.pwdIcon = '/static/images/icon_turn.png'
			 			}else{
			 				
							this.pwdIcon = '/static/images/eye2.png'
			 			}
			                  },
			 	
		
						zhuce(){
							uni.redirectTo({
							                        url: '/pages/zhuce/zhuce'
							                    });
						},
						denglu(){
							uni.switchTab({
							                        url: '/pages/device/device'
							                    });
						}
						
		},
		}
 
</script>
<style>
	input{ font-size: 32upx; padding: 10upx 0 0 0; width: 100%; }
	.pwdImg{ width: 40upx ; height: 30upx; }
	.userback {
		height: 216px;
		background-image: url('../../static/image/jia1.png');
		background-repeat: no-repeat;
		background-size: 100%;
		text-align: center
	}
 
	.userback img {
		
		margin: auto;
		border-radius: 54px;
		margin-top: 21%;
		width: 150px;
		height: 150px;
	}
	.userName{
		color: #111111;
		font-size: 48rpx;
		font-weight:bolder
	}
	.userOrgan{		
	}	
	/* button {
	    margin: unset;
	    padding: unset;
	}
	button:after {
		 border: unset;
		 
	} */
	.btn-row{
		margin: 0 10%;
		padding: 5px;
	
	}
	.btn-row1{
		margin: 0 10%;
		padding: 5px;
		
	}
	/* uni-button[type=primary] {
		
	    margin: 0 10%;
	    background-image: linear-gradient(to top, #66b7f9,#1c82d4);
		
	}
	uni-button[type=default] {
		
	    margin: 0 10%;
	    background-image: linear-gradient(to top, #66b7f9,#1c82d4);
		
	} */
	.cu-list.menu-avatar>.cu-item {	   
	    height: 50px;
	    background:#fff;
		
	}
	.cu-list.menu-avatar>.cu-item .content {	
	   
	   background-color: #e0e0e0;
	   padding: 20rpx;
	   margin: 40rpx;
	   border:1 px solid #666;
	   text-align: center;
	 
	}
	.content1{
		flex-flow: row;
				justify-content: flex-start;
				display: flex;
	}
	.cu-list.menu-avatar>.cu-item .content1 {
	   
	   background-color: #e0e0e0;
	   padding: 20rpx;
	   margin: 40rpx;
	   border:1 px solid #666;
	   text-align: center;
	 
	}
	.cu-list.menu-avatar>.cu-item .action {
	
		text-align: center; 
	}
	.cu-list.menu-avatar {	   
	    height: 180px;
	}
</style>