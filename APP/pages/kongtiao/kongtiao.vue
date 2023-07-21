<template>
	<view>
		<text class="kongtiao-kaiguan">{{wendushedingkaiguan}}</text>
		<view class="kongtiaokongzhi">
		
		<view class="chuifengmoshi">
		<image class="chuifengmoshi-img" src="/static//image/fengsu.png"></image>
		<text class="chuifengmoshi-text">{{chuifengmoshitext}}</text>
		</view>
		<!-- <view class="tongfengzhuangtau">
		<image class="tongfengzhuangtai-img" src="/static//image//tongfengzhuangtai.png"></image>
		<text class="tongfengzhuangtai-text">{{tongfengzhuangtaitext}}</text>
		</view> -->
		<view class="wendusheding">
		<image class="wendusheding-img" src="/static//image//moshi11.png"></image>
		<text class="wendusheding-text">{{wendushedingtext}}</text>
		</view>

		<view class="wendushuzhi" >
			<image class="wendusheding-img" src="/static//image//wendu11.png"></image>
			<view class="">温度设定：{{num}}</view>
			<!-- <view class="">{{num}}</view> -->
		</view>
		
		</view>
	<view>
		 <image class="fengexian" src="/static/image/fengexian1.png"></image>
	</view>
		 <view class="kaiguan">
		  <view class="list-cell1">
		 
		  	<image class="kaiguan1" src="/static/image/kaiguan2.png" @click="dakai()"></image>
		 	<text class="kaiguan1text">空调开关</text>
		 	
		 	
		  </view>
		  <view class="list-cell2">
			  <image class="kaiguan2" src="/static/image/tongfeng.png" @click="tongfeng()"></image>
			  <text class="kaiguan2text">通风</text>
		  	<image class="kaiguan1" src="/static/image/zhileng.png" @click="zhileng()"></image>
		  	<text class="kaiguan1text">制冷</text>
		  	<image class="kaiguan2" src="/static/image/zhire.png" @click="zhire()"></image>
		  	<text class="kaiguan2text">制热</text>
		  </view>
		  <view class="list-cell3">
		  	<image class="kaiguan1" src="/static/image/difeng.png" @click="difeng()"></image>
		  	<text class="kaiguan1text">低风</text>
		  	<image class="kaiguan2" src="/static/image/zhongfeng.png" @click="zhongfeng()"></image>
		  	<text class="kaiguan2text">中风</text>
			<image class="kaiguan1" src="/static/image/gaofeng.png" @click="gaofeng()"></image>
			<text class="kaiguan1text">高风</text>
		  </view>
		  <view class="list-cell4">
		  	<image class="kaiguan2" src="/static/image/wendu1.png" ></image>
		  	<text class="kaiguan2text">温度:</text>
		 	<image class="kaiguan2" src="/static/image/shangsheng.png" @click="tiaogao()"></image>
		 	<text class="kaiguan2text">调高</text>
			<image class="kaiguan1" src="/static/image/xiajiang.png" @click="tiaodi()"></image>
			<text class="kaiguan1text">调高</text>
		  </view>
		  
		 </view>
		 <image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
	</view> 
	
	</view>
</template>

<script>
	export default {
		
		data() {
		
			return {
				list:[],
			buttonType: '',	
			chuifengmoshitext:"吹风模式：中风",
			// tongfengzhuangtaitext:"通风状态：无",
			wendushedingtext:"模式设定：制冷",
			wendushedingkaiguan:"空调开关状态：关",
			num:25,
			}
			
		},
				
		methods: {
		
			dakai:function(){
				if(this.wendushedingkaiguan === "空调开关状态：开")
				{
					this.wendushedingkaiguan = "空调开关状态：关";
				}else if(this.wendushedingkaiguan === "空调开关状态：关") {
					this.wendushedingkaiguan = "空调开关状态：开";
				}
					  // let that = this;
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":0,
							  "place":"2"
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			// guanbi:function(){
			// 		  this.wendushedingkaiguan="空调开关状态：关",
			// 		  uni.request({
			// 		  	url:'http://114.116.248.29:5000/air',
			// 			method:'POST',
			// 			header: {
			// 			  'content-type': 'application/json'  
			// 			 },
			// 			 data:{
			// 				 "changeflag":0,
			// 				  "place":"1"
			// 			 },
			// 			success:res=>{
			// 				return uni.showToast({
			// 					title: "关闭成功"
			// 				})
			// 			},
			// 			fail: (err) => {
			// 				return uni.showToast({
			// 					title: "关闭失败"
			// 				})
							
					  
			// 	  },
			// 	  })
			// },
			tongfeng:function(){
				this.wendushedingtext="模式设定：通风",
					  
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":2,
							  "place":"2",
							  "mode":3
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			
			zhileng:function(){
					  this.wendushedingtext="模式设定：制冷",
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":2,
							  "place":"2",
							  "mode":1
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			zhire:function(){
					   this.wendushedingtext="模式设定：制热",
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":2,
							  "place":"2",
							  "mode":2
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			difeng:function(){
				
					   this.chuifengmoshitext="吹风模式：低风",
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":3,
							  "place":"2",
							  "wind":1
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			zhongfeng:function(){
					    this.chuifengmoshitext="吹风模式：中风",
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":3,
							  "place":"2",
							  "wind":2
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			gaofeng:function(){
					    this.chuifengmoshitext="吹风模式：高风",
					  uni.request({
					  	url:'http://114.116.248.29:5000/air',
						method:'POST',
						header: {
						  'content-type': 'application/json'  
						 },
						 data:{
							 "changeflag":3,
							  "place":"2",
							  "wind":3,
						 },
						success:res=>{
							return uni.showToast({
								title: "成功"
							})
						},
						fail: (err) => {
							return uni.showToast({
								title: "失败"
							})
							
					  
				  },
				  })
			},
			tiaogao:function(){
				this.num = this.num + 1;
				uni.request({
									  	url:'http://114.116.248.29:5000/air',
										method:'POST',
										header: {
										  'content-type': 'application/json'  
										 },
										 data:{
											 "changeflag":1,
											  "place":"2",
											  "temp":1,
										 },
										success:res=>{
											return uni.showToast({
												title: "成功"
											})
										},
										fail: (err) => {
											return uni.showToast({
												title: "失败"
											})
											
									  
				},
				})
				
			},
		
		   tiaodi:function(){
			this.num = this.num - 1;
			uni.request({
								  	url:'http://114.116.248.29:5000/air',
									method:'POST',
									header: {
									  'content-type': 'application/json'  
									 },
									 data:{
										 "changeflag":1,
										  "place":"2",
										  "temp":2,
									 },
									success:res=>{
										return uni.showToast({
											title: "成功"
										})
									},
									fail: (err) => {
										return uni.showToast({
											title: "失败"
										})
										
								  
			},
			})
		},
		}
		
	}
</script>

<style lang="scss">
	.fengexian{
		top:10px;
		height: 30px;
		width: 100%;
	}
	.kongtiao-kaiguan{
		font-size: 20px;
		display: flex;
		justify-content: left;
		align-items: center;
		font-weight: bold;
	}
	.kongtiaokongzhi{
	  display: grid;
	  grid-template-columns: repeat(3, 30%);
	  margin-top: 50rpx;
	   padding: rpx;
	   
.chuifengmoshi-img{
	max-width: 100rpx;
	max-height: 100rpx;
	margin: 0 auto;
	display: block;
	padding: 30rpx;
	}
.chuifengmoshi-text{
	
		font-size: 15px;
		display: flex;
		justify-content: left;
		align-items: center;
	}
.tongfengzhuangtai-img{
		max-width: 100rpx;
		max-height: 100rpx;
		margin: 0 auto;
		display: block;
		padding: 30rpx;
}
.tongfengzhuangtai-text{
	font-size: 15px;
	display: flex;
	justify-content: left;
	align-items: center;
}
.wendusheding-img{
		max-width: 100rpx;
		max-height: 100rpx;
		margin: 0 auto;
		display: block;
		padding: 30rpx;
}
.wendusheding-text{
	font-size: 15px;
	display: flex;
	justify-content: left;
	align-items: center;
}
}
.kongtiao{
	font-size: 15px;
	display: flex;
	justify-content: left;
	align-items: center;
}
.mensuo-img{
		
		position: fixed;
		    width: 100%;
		    height: 100%;
		    top: 0;
		    left: 0;
		    z-index: -1;
	}
	.kaiguan{
		margin-top: 30px;
		
	.list-cell1{
		
	padding: 10px;
	flex-flow: row;
			justify-content: flex-start;
			
			display: flex;
	
	.kaiguan1{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		margin-right: 20px;
		font-size: 20px;
	}
	
		.kaiguan2{
			
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan2text{
		margin-top:18px;
		margin-right: 10px;
		font-size: 20px;
	}
	}
	.list-cell2{
		
	padding: 10px;
	flex-flow: row;
			justify-content: flex-start;
			display: flex;
	.kaiguan1{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		font-size: 20px;
	}
	.kaiguan2{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan2text{
		margin-top:18px;
		font-size: 20px;
	}
	}
	.list-cell3{
		
		padding: 10px;
		flex-flow: row;
				justify-content: flex-start;
				display: flex;
	.kaiguan1{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		font-size: 20px;
	}
	.kaiguan2{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan2text{
		margin-top:18px;
		font-size: 20px;
	}
	}
	.list-cell4{
		
		padding: 10px;
		flex-flow: row;
				justify-content: flex-start;
				display: flex;
	.kaiguan1{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		font-size: 20px;
	}
	.kaiguan2{
		padding: 15px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan2text{
		margin-top:18px;
		font-size: 20px;
	}
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
