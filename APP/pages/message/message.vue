//第一种是简单登录
<template>
	<view>
		
		<view class="margin bg-fff padding-xl radius shadow-warp bg-white margin-top">
			<!-- 图标 -->
			<view class="text-center ">
				<image class="avatar" src="/static/image/denglujiemian.png" mode=""></image>
			</view>
			<!-- 账号密码 -->
			<view class="login_form">
				<view class="login_form_input">
					
					<view name="username">
						<input  prefixIcon="person" placeholder="请输入登录用户名">
						</input>
					</view>
					</view>
					<view class="login_form_input1">
					<view name="password">
						<input  prefixIcon="person" placeholder="请输入密码">
						</input>
					</view>
					</view>

			</view>
			
		</view>
		<!-- 按钮 -->
		<view class="enter">
		<!-- 	<navigator url="/pages/message/message" open-type="switchTab" hover-class="other-navigator-hover"> -->
				<button type="default"  @click="jinru()">登录</button>
				<button type="default"  @click="zhuce()">注册</button>
			<!-- </navigator> -->
		</view>
		<!-- <navigator url="xxxx" style="margin: 10rpx 40rpx; color: deepskyblue;">前往注册</navigator> -->
	</view>
</template>
 
<script>
	export default {
		
		data() {
			
			return {
				
		
			}
		},
		methods: {
			// then方式的 .then 要这样获取,不要用res就好了 会跟内部定义的属性名冲突 
			//这个是固定死的登陆方法
			zhuce(){
				uni.redirectTo({
				                        url: '/pages/zhuce/zhuce'
				                    });
			},
			jinru(){
				uni.switchTab({
				                        url: '/pages/device/device'
				                    });
			}
           // 获取localstorage的数据；记得set一个账号密码，这边已缓存为前提
		// 		uni.getStorage({
		// 			key: 'form',
		// 			success: (res) => {
		// 				let key = this.form
  //                     //      把账号密码固定，zhangsan&123
		// 				if (key.username == 'zhangsan' && key.password == '123456') {
		// 					console.log('登陆成功');
		// 					// uni.showToast({
		// 					// 	mask: true,
		// 					// 	title: "登录成功",
		// 					// 	icon: 'success',
		// 					// 	duration: 1500
		// 					// });
  //      //                  // 登陆成功时，定时跳转
		// 					setTimeout(function() {
		// 						uni.redirectTo({
  //                               //链接到页面
		// 							url: '/pages/device/device' 
		// 						});
		// 					}, 1000);
		// 				} else {
		// 					console.log('账号或密码错误');
		// 					uni.showToast({
		// 						title: '账号或密码错误',
		// 						icon: "error"
		// 					});
		// 				}
		// 			},
		// 		})
		// 	}
		// }
		}
	}
</script>
<style lang="scss">
	.avatar{
		width: 200px;
		height: 200px;
		top:10px;
		display: block;
		margin: 0 auto;
		padding: 10px;
		
	}
	.login_form{
		padding: 20px;
	.login_form_input{
		width: 200px;
		height: 50px;
	}
	.login_form_input1{
		width: 200px;
		height: 50px;
	}
	
	}
	
	</style>