<template>
	<view>
		<text class="chuanglian-kaiguan">{{chuangliankaiguan}}</text>
		<view class="btn">
		<button style="background-color:#ffffff" @click="guanbi()">窗帘上升</button>
		</view>
		<view class="btn1">
		<button style="background-color:#ffffff" @click="dakai()">窗帘下降</button>
		</view>
		<image class="chuanglian-img" src="/static/image//beijing1.jpg"></image>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				chuangliankaiguan:"窗帘开关状态:下降",
			}
		},
		methods: {
			dakai:function(){
				this.chuangliankaiguan = "窗帘开关状态:下降"
				uni.request({
									  	url:'http://114.116.248.29:5000/curtain',
										method:'POST',
										header: {
										  'content-type': 'application/json'  
										 },
										 data:{
											  "place":"0",
											  "mode":1
										 },
										success:res=>{
											return uni.showToast({
												title: "窗帘下降成功"
											})
										},
										fail: (err) => {
											return uni.showToast({
												title: "失败"
											})
											
									  
				},
				})
			},
			guanbi:function(){
				this.chuangliankaiguan = "窗帘开关状态:上升"
				uni.request({
									  	url:'http://114.116.248.29:5000/curtain',
										method:'POST',
										header: {
										  'content-type': 'application/json'  
										 },
										 data:{
											  "place":"0",
											  "mode":2
										 },
										success:res=>{
											return uni.showToast({
												title: "窗帘上升成功"
											})
										},
										fail: (err) => {
											return uni.showToast({
												title: "失败"
											})
											
									  
				},
				})
			}
		}
	}
</script>

<style>
	.chuanglian-kaiguan{
		font-size: 30px;
		display: flex;
		justify-content: left;
		align-items: center;
		font-weight: bold;
		padding:30px
	}
	
.chuanglian-img{
		/* width: 750rpx;
		height: 650rpx;
		margin: 0 auto;
		display: block;
		padding: 5rpx; */
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
