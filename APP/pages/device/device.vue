<template>
	<view>
  <view class="uni-margin-wrap">
	  <swiper class="swiper" circular indicator-dots="true" autoplay="true" interval=2000 duration=500>
	  		<swiper-item>
	  			<view class="swiper-item">
	  				<image src="../../static/image/shebei1.jpg"></image>
	  
	  			</view>
	  		</swiper-item>
	  		<swiper-item>
	  			<view class="swiper-item">
	  				<image src="../../static/image/shebei2.jpg"></image>
	  
	  			</view>
	  		</swiper-item>
	  		<swiper-item>
	  			<view class="swiper-item">
	  				<image src="../../static/image/shebei3.png"></image>
	  
	  			</view>
	  		</swiper-item>
	  		<swiper-item>
	  			<view class="swiper-item">
	  				<image src="../../static/image/shebei4.jpg"></image>
	  
	  			</view>
	  		</swiper-item>
	  	</swiper>
	  </view>
	  <view class="partitions" >
    <navigator class="partition" redirect v-for="(partition, index) in partitions" @click="dengguang(partition.title)":key="index">
      <image class="partition-img" :src="partition.image" alt="">
      <view class="partition-title"  >{{partition.title}}</view>
    </navigator>
  </view>
  	<image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
  </view>
</template>

<script>
var _self;
export default {
  name: 'partition',
  
  data(){
    return {
      partitions:[
        {title:'灯光', image: '../../static/image/Table lamp.gif'},
		{title: '客厅空调', image: '../../static/image/kongtiao.gif'},
		{title: '主卧空调', image: '../../static/image/kongtiao11.gif'},
		{title: '次卧空调', image: '../../static/image/kongtiao12.gif'},
        {title: '门锁', image: '../../static/image/Padlock.gif'},
        {title: '温湿度', image: '../../static/image/Water drops.gif'},
        {title: '窗帘', image: '../../static/image/WVQLP89LXC1V0H8GW5[AV%60Q.gif'},
        {title: '离家模式', image: '../../static/image/38.gif'},
		{title: '睡眠模式', image: '../../static/image/shuimian.gif'},
      ],
	  activeIndex: 0
    }
  },
  methods: {
  			dengguang(title) {
  			if(title == '灯光') {
  			uni.navigateTo({
  			                   
  			                    url: "/pages/dengguang/dengguang"
  			
  			                })
  			}
			if(title == '客厅空调') {
			uni.navigateTo({
			                   
			                    url: "/pages/ketingkongtiao/ketingkongtiao"
			
			                })
			}
  			if(title == '主卧空调') {
  			uni.navigateTo({
  			                   
  			                    url: "/pages/kongtiao/kongtiao"
  			
  			                })
  			}
			if(title == '次卧空调') {
			uni.navigateTo({
			                   
			                    url: "/pages/ciwokongtiao/ciwokongtiao"
			
			                })
			}
			if(title == '门锁') {
			uni.navigateTo({
			                   
			                    url: "/pages/mensuo/mensuo"
			
			                })
			}
			if(title == '温湿度') {
				uni.navigateTo({
				                   
				                    url: "/pages/jiankong/jiankong"
				
				                })
			
			}
			if(title == '窗帘') {
				uni.navigateTo({
				                   
				                    url: "/pages/chuanglian/chuanglian"
				
				                })
			
			}
			if(title =='离家模式'){
				uni.request({
				  		  	url:'http://114.116.248.29:5000/global',
				  			method:'POST',
				  			header: {
				  			  'content-type': 'application/json'  
				  			 },
				  			 data:{
				  				 "mode":"leave",
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
			}
			if(title =='睡眠模式'){
				uni.request({
				  		  	url:'http://114.116.248.29:5000/global',
				  			method:'POST',
				  			header: {
				  			  'content-type': 'application/json'  
				  			 },
				  			 data:{
				  				 "mode":"sleep",
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
			}
			
  			}
				
				},
				}
 
 </script>



<style lang="scss">
	.mensuo-img{
			
			position: fixed;
			    width: 100%;
			    height: 100%;
			    top: 0;
			    left: 0;
			    z-index: -1;
		}
	.swiper {
		height: 500rpx;
		width:400px
	}
	
	.swiper-item {
		text-align: center;
		height: 100%;
	
		image {
			width: 100%;
			height: 100%;
		}
	}
	
.partitions{
  display: grid;
  grid-template-columns: repeat(3, 33%);
  margin-top: 50rpx;
 
  .partition {
    padding: 30rpx;
    .partition-img{
      max-width: 150rpx;
      max-height:150rpx;
      margin: 0 auto;
      display: block;
    }
    .partition-title{
      font-size: 20px;
      display: flex;
      justify-content: center;
      align-items: center;
    }
  }
}

</style>