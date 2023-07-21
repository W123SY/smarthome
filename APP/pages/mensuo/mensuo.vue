<template>
	<view>
		
		<text class="mensuokaiguan">{{mensuo}}</text>
		<view class="btn">
		<button  style="background-color:#ffffff" @click="yijiankaisuo()">一键开锁</button>
		</view>
		<view class="btn1">
		<button  style="background-color:#ffffff" @click="yijianguansuo()">一键关锁</button>
		</view>
		<image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				mensuo:"门锁开关状态：关"
			}
		},
		methods: {
			yijiankaisuo:function(){
				this.mensuo = "门锁开关状态:开",
				uni.request({
									  	url:'http://114.116.248.29:5000/lock',
										method:'POST',
										header: {
										  'content-type': 'application/json'  
										 },
										 data:{
											 
											  "flag":"0"
										 },
										success:res=>{
											return uni.showToast({
												title: "打开成功"
											})
										},
										fail: (err) => {
											return uni.showToast({
												title: "打开失败"
											})
											
									  
				},
				})
			},
			yijianguansuo:function(){
				this.mensuo = "门锁开关状态:关",
				uni.request({
									  	url:'http://114.116.248.29:5000/lock',
										method:'POST',
										header: {
										  'content-type': 'application/json'  
										 },
										 data:{
											 
											  "flag":"1"
										 },
										success:res=>{
											return uni.showToast({
												title: "关闭成功"
											})
										},
										fail: (err) => {
											return uni.showToast({
												title: "关闭失败"
											})
											
									  
				},
				})
			},
			
		}
	}
</script>

<style lang="scss">
	.mensuokaiguan{
		font-size: 30px;
		display: flex;
		justify-content: left;
		align-items: center;
		font-weight: bold;
		padding:30px;
	}
.mensuo-img{
		
		position: fixed;
		    width: 100%;
		    height: 100%;
		    top: 0;
		    left: 0;
		    z-index: -1;
	}
	.btn{
		margin: 0 10%;
		padding: 5px;
	}
	.btn1{
		margin: 0 10%;
		padding: 10px;
	}
</style>
