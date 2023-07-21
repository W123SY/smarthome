<template>
	
  <view>
	  <view class="dengguangs" >
    <navigator class="dengguang" redirect v-for="(dengguang, index) in dengguangs" :key="index" >
      <image class="dengguang-img" :src="dengguang.image" alt="">
      <view class="dengguang-title">{{dengguang.title}}</view>
	  <view class="dengguang-message">
	  <text>{{dengguang.message}}
	  </text>
	  </view>
	  <view class="dengguang-con">{{dengguang.con}}</view>
    </navigator>
  </view>
  <view >
	  <image class="fengexian" src="/static/image/fengexian.png"></image>
  </view>
  
 <!-- <view class="kaiguan">
  <view class="control">

	  <button :type="buttonType" @click="changeTextValue1()">一键全开</button>
	  <button :type="buttonType" @click="changeTextValue7()">一键全关</button>
	
	  <button :type="buttonType" @click="changeTextValue2()">开关厨房灯</button>
	  
	
	   <button :type="buttonType" @click="changeTextValue3()">开关客厅灯</button>
	    
	
	   <button :type="buttonType" @click="changeTextValue4()">开关主卧灯</button>
	   
	  
	   <button :type="buttonType" @click="changeTextValue5()">开关次卧灯</button>
	   
	    
	   <button :type="buttonType" @click="changeTextValue6()">开关浴室灯</button>
	   
	    
	
	  
	  
 </view> 
 </view> -->
 <view class="kaiguan">
 <view class="list-cell1">

 	<image class="kaiguan1" src="/static/image/kaiguan2.png" @click="changeTextValue1()"></image>
	<text class="kaiguan1text">一键全开</text>
	
	<image class="kaiguan2" src="/static/image/kaiguan2.png" @click="changeTextValue7()"></image>
	<text class="kaiguan2text">一键全关</text>
 </view>
 <view class="list-cell2">
 	<image class="kaiguan1" src="/static/image/kaiguan2.png" @click="changeTextValue2()"></image>
 	<text class="kaiguan1text">客厅灯开关</text>
 	<image class="kaiguan2" src="/static/image/kaiguan2.png" @click="changeTextValue3()"></image>
 	<text class="kaiguan2text">主卧灯开关</text>
 </view>
 <view class="list-cell3">
 	<image class="kaiguan1" src="/static/image/kaiguan2.png" @click="changeTextValue4()"></image>
 	<text class="kaiguan1text">次卧灯开关</text>
 	<image class="kaiguan2" src="/static/image/kaiguan2.png" @click="changeTextValue5()"></image>
 	<text class="kaiguan2text">厨房灯开关</text>
 </view>
 <view class="list-cell4">
 	<image class="kaiguan1" src="/static/image/kaiguan2.png" @click="changeTextValue6()"></image>
 	<text class="kaiguan1text">浴室灯开关</text>
	<image class="kaiguan2" src="/static/image/kaiguan2.png" @click="changeTextValue8()"></image>
	<text class="kaiguan2text">感应控制</text>
 	
 </view>
 <view class="list-cell4">
 	
 	<image class="kaiguan2" src="/static/image/kaiguan2.png" @click="changeTextValue9()"></image>
 	<text class="kaiguan2text">智能控制</text>
 	
 </view>
</view>
 
 <image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
 
 </view>
</template>

<script>

export default {
  name: 'dengguang',
  
  data(){
    return {
		buttonType: '',
      dengguangs:[
        {title:'厨房', image: '../../static/image/Cutlery plate.gif',message:'灯光状态: 关'},
        {title: '客厅', image: '../../static/image/TV stand.gif',message:'灯光状态: 关'},
        {title: '浴室', image: '../../static/image/Bath.gif',message:'灯光状态: 关'},
        {title: '主卧', image: '../../static/image/Bed.gif',message:'灯光状态: 关'},
        {title: '次卧' ,image: '../../static/image/Computer desk.gif',message:'灯光状态: 关'},	
       
      ]
    }
	// onload(){
	// 	this.getlist();
		
	// }
  },
  methods:{
	  // getlist(){
		 //  uni.request({
		  	
		 //  })
	  // }
	
	  changeTextValue1:function(){
		  this.dengguangs[0].message='灯光状态: 开';
		  // this.dengguangs[1].message='灯光状态: 开';
		  // this.dengguangs[2].message='灯光状态: 开';
		  // this.dengguangs[3].message='灯光状态: 开';
		  // this.dengguangs[4].message='灯光状态: 开';
		  if(this.dengguangs[2].message !='感应控制'){
			  this.dengguangs[2].message='灯光状态: 开';
		  }
		  if(this.dengguangs[1].message !='智能控制'){
		  			  this.dengguangs[2].message='灯光状态: 开';
		  }
		  if(this.dengguangs[3].message !='智能控制'){
		  			  this.dengguangs[3].message='灯光状态: 开';
		  }
		  if(this.dengguangs[4].message !='智能控制'){
		  			  this.dengguangs[4].message='灯光状态: 开';
		  }
		  let that = this;
		  uni.request({
		  	url:'http://114.116.248.29:5000/light',
			method:'POST',
			header: {
			  'content-type': 'application/json'  
			 },
			 data:{
				 "place":"all",
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
  changeTextValue7:function(){
	  this.dengguangs[0].message='灯光状态: 关';
	  // this.dengguangs[1].message='灯光状态: 关';
	  
	  // this.dengguangs[3].message='灯光状态: 关';
	  // this.dengguangs[4].message='灯光状态: 关';
	  if(this.dengguangs[2].message !='感应控制'){
	  			  this.dengguangs[2].message='灯光状态: 关';
	  }
	  
	  if(this.dengguangs[1].message !='智能控制'){
	  			  this.dengguangs[2].message='灯光状态: 关';
	  }
	  if(this.dengguangs[3].message !='智能控制'){
	  			  this.dengguangs[3].message='灯光状态: 关';
	  }
	  if(this.dengguangs[4].message !='智能控制'){
	  			  this.dengguangs[4].message='灯光状态: 关';
	  }
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"none",
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
  changeTextValue2:function(){
	  if(this.dengguangs[0].message === '灯光状态: 关')
	  {
	  this.dengguangs[0].message='灯光状态: 开';
	  }
	  else if(this.dengguangs[0].message ==='灯光状态: 开')
	  {
	  this.dengguangs[0].message='灯光状态: 关';
	  }
  		  // let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"1",
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
  changeTextValue3:function(){
	  if(this.dengguangs[1].message === '灯光状态: 关')
	  {
	  this.dengguangs[1].message='灯光状态: 开';
	  }
	  else if(this.dengguangs[1].message ==='灯光状态: 开')
	  {
	  this.dengguangs[1].message='灯光状态: 关';
	  }
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"2",
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
  changeTextValue4:function(){
	  if(this.dengguangs[2].message === '灯光状态: 关')
	  {
	  this.dengguangs[2].message='灯光状态: 开';
	  }
	 
	  else if(this.dengguangs[2].message ==='灯光状态: 开')
	  {
	  this.dengguangs[2].message='灯光状态: 关';
	  }
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"3",
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
  changeTextValue5:function(){
	  if(this.dengguangs[3].message === '灯光状态: 关')
	  {
	  this.dengguangs[3].message='灯光状态: 开';
	  }
	  else if(this.dengguangs[3].message ==='灯光状态: 开')
	  {
	  this.dengguangs[3].message='灯光状态: 关';
	  }
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"4",
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
  changeTextValue6:function(){
	  if(this.dengguangs[4].message === '灯光状态: 关')
	  {
	  this.dengguangs[4].message='灯光状态: 开';
	  }
	  
	  else if(this.dengguangs[4].message ==='灯光状态: 开')
	  {
	  this.dengguangs[4].message='灯光状态: 关';
	  }
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"5",
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
  changeTextValue8:function(){
  	  if(this.dengguangs[2].message !='感应控制'){
		  this.dengguangs[2].message ='感应控制'
	  }
	  else if(this.dengguangs[2].message ='感应控制'){
		  this.dengguangs[2].message ='灯光状态：关'
	  }
	  
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"6",
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
  changeTextValue9:function(){
  	  if(this.dengguangs[1].message !='智能控制'){
  		  this.dengguangs[1].message ='智能控制'
  	  }
  	  else if(this.dengguangs[1].message ='智能控制'){
  		  this.dengguangs[1].message ='灯光状态：开'
  	  }
	  if(this.dengguangs[3].message !='智能控制'){
	    		  this.dengguangs[3].message ='智能控制'
	  }
	  else if(this.dengguangs[3].message ='智能控制'){
	    		  this.dengguangs[3].message ='灯光状态：开'
	  }
	  if(this.dengguangs[4].message !='智能控制'){
	    		  this.dengguangs[4].message ='智能控制'
	  }
	  else if(this.dengguangs[4].message ='智能控制'){
	    		  this.dengguangs[4].message ='灯光状态：开'
	  }
	  
  	  
  		  let that = this;
  		  uni.request({
  		  	url:'http://114.116.248.29:5000/light',
  			method:'POST',
  			header: {
  			  'content-type': 'application/json'  
  			 },
  			 data:{
  				 "place":"LightSensing",
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
  }}
</script>

<style lang ="scss">
	.fengexian{
		top:-50px;
		height: 100px;
		width: 100%;
	}
	.kaiguan{
		margin-top: -60px;
		
	.list-cell1{
		
	padding: 10px;
	flex-flow: row;
			justify-content: flex-start;
			
			display:flex;

	.kaiguan1{
		padding: 10px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		
		margin-right: 20px;
		font-size: 20px;
	}
	
		.kaiguan2{
			
		padding: 10px;
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
		padding: 10px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		font-size: 20px;
	}
	.kaiguan2{
		padding: 10px;
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
		padding: 10px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		
		margin-top:18px;
		
		font-size: 20px;
	}
	.kaiguan2{
		padding: 10px;
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
		padding: 10px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan1text{
		margin-top:18px;
		font-size: 20px;
	}
	.kaiguan2{
		padding: 10px;
		max-width: 70rpx;
		max-height: 70rpx;
	}
	.kaiguan2text{
		margin-top:18px;
		font-size: 20px;
	}
	}
	}
	
	
	
.dengguangs{
	padding: 5px;
  display: grid;
  grid-template-columns: repeat(2, 50%);
  margin-top: 5rpx;
 
  .dengguang {
    padding: 5rpx;
    .dengguang-img{
      max-width:150rpx;
      max-height: 150rpx;
      margin: 0 auto;
      display: block;
    }
    .dengguang-title{
      font-size: 20px;
      display: flex;
      justify-content: center;
      align-items: center;
    }
	.dengguang-message{
		font-size: 20px;
		display: flex;
		justify-content: left;
		align-items: center;
	}
  }
  
}
/* .kaiguan{
/* 	flex-flow: row;
			justify-content: flex-start;
			display: flex; */
  /* display: grid;
  grid-template-columns: repeat(2, 50%);
  margin-top: 1rpx;
.control {
    padding: 10rpx;
}
} */ 
.mensuo-img{
		
		position: fixed;
		    width: 100%;
		    height: 100%;
		    top: 0;
		    left: 0;
		    z-index: -1;
	}

</style>
