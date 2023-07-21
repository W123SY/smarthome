<template>
	<view>
		<!-- <button type=" " @click="getdat()">刷新页面</button> -->
		<text class="shuju" @click="getdat()">房间温湿度及报警数据：</text>
		<view class="list-cell" @click="shiming()" hover-class="cell-hover" :hover-stay-time="50">
			<image class="img1" src="../../static/image/wendu12.png"></image>
			<text class="cell-tit">温度：{{mm[134]}}{{mm[135]}}{{mm[136]}}{{mm[137]}}</text>
			
			
			<!-- <text class="cell-more yticon icon-you"></text> -->
		</view>
		<view class="list-cell1" @click="shiming()" hover-class="cell-hover" :hover-stay-time="50">
			<image class="img2" src="../../static/image/shidu12.png">
			<text class="cell-tit1">湿度：{{mm[62]}}{{mm[63]}}{{mm[64]}}{{mm[65]}}</text>
			
			<text class="cell-more yticon icon-you"></text>
		</view>
		<!-- <text class="shuju" @click="getdat()">烟雾报警：</text> -->
		<view class="list-cell1" @click="shiming()" hover-class="cell-hover" :hover-stay-time="50">
			<image class="img2" src="../../static/image/huo.png">
			<text class="cell-tit1">火焰报警：{{yanwu}}</text>
			
			<text class="cell-more yticon icon-you"></text>
			<view class="list-cell1" @click="shiming()" hover-class="cell-hover" :hover-stay-time="50">
				<image class="img2" src="../../static/image/rentijiance.png">
				<text class="cell-tit1">入侵检测：{{ruqin}}</text>
				
				<text class="cell-more yticon icon-you"></text>
				</view>
		</view>
		
		<view class="wenshidu">
		
		</view>
		  <image class="mensuo-img" src="/static/image//beijing1.jpg"></image>
	</view>
</template>

<script>
	// import TopAndRefresh from '@/components/topAndRefresh.vue'
	export default {
		// watch:{
		// callMyInviter (){//发短信
		
		// var msg = plus.messaging.createMessage(plus.messaging.TYPE_SMS);
		
		// msg.to = [this.inviterInfo.phone];
		
		// msg.body = 'This is HTML5 Plus example test message';
		
		// plus.messaging.sendMessage( msg );
		
		// }
		// }
		// yanwu (newName, oldName) {
		//         this.callMyInviter()
		//     }
		// },
		
		
		// components: {
		//     TopAndRefresh
		//   },
		data() {
			return {
				mm:"",
				wendu:"",
				yanwu:"",
				ruqin:"",
				
			}
		},
		    // onPageScroll(e) {
			   //  this.isTopAndRefresh = e.scrollTop > 500;
		    // },
		onLoad() {
			this.getmm();
			// this.getitem();
			// this.callMyInviter();
			// this.getyanwu();
		},
		methods: {
			
			getdat() {
				uni.redirectTo({
					url: '/pages/jiankong/jiankong',
				});
			},
			
			
			getmm(){
			uni.request({
				url: 'http://114.116.248.29:5000/humiture',
				data: {
				    "changeflag":0,
				     "place":"1"
				},
				header: {
					'content-type': 'application/json'
				},
				success: (res) => {
					
					
					this.mm = JSON.stringify(res.data);
					if(this.mm[28] == "1"){
						this.yanwu = "报警";
						
						}
					else if(this.mm[28] != "1"){this.yanwu = "正常"}
				    if(this.mm[97] == "1"){this.ruqin = "入侵"}
					else if(this.mm[97] != "1"){this.ruqin = "正常"}
				// JSON.stringify(temperatyre);
				}
			})
}
		},
	// 	        fetchList() {
	// 	            // 请求
	// 	        }
	// callMyInviter (){//发短信
	
	// // let msg = plus.messaging.createMessage(plus.messaging.TYPE_SMS);
	
	// // msg.to = [this.inviterInfo.phone];
	
	// // msg.body = 'This is HTML5 Plus example test message';
	
	// // plus.messaging.sendMessage( msg );
	// let msg = plus.messaging.createMessage(plus.messaging.TYPE_SMS)
	// msg.to = ['18954552367']
	// msg.body = '报警'
	// plus.messaging.sendMessage(msg)
	// },
	
	//      getitem(){
	// 			uni.request({
	// 				url: 'http://114.116.248.29:5000/humiture',
	// 				data: {
	// 				    "changeflag":0,
	// 				     "place":"1"
	// 				},
	// 				header: {
	// 					'content-type': 'application/json'
	// 				},
	// 				success: (res) => {
						
	// 					this.wendu = JSON.stringify(res.data);
						
				
	// 				}
	// 			})
	// }
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
		
			.img1{
				padding-top:10px;
				left: 10px;
				height: 100px;
				width: 100px;
				padding: 10px;
			}
			.cell-tit{
				margin-top: 10px;
				margin-left:30px;
				font-size: 20px;
			}
			.img2{
				padding-top:10px;
				height: 100px;
				width: 100px;
				padding: 20px;
			}
			.cell-tit1{
				margin-left:10px;
				font-size: 20px;
			}
.shuju{
	color: 	#000000;
	font-size: 30px;
	font-weight: bold;
	padding: 20px;
}		
/* .list-cell{
			display:flex;
			align-items:baseline;
			padding: 20upx 30upx;
			line-height:60upx;
			position:relative;
			background: #fff;
			height: 100px;
			justify-content: center;
			&.log-out-btn{
				margin-top: 40upx;
				.cell-tit{
					color: #007aff;
					text-align: center;
					margin-right: 0;
				}
			}
			} */
</style>
