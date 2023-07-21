<template>
	<view>
		<view class="uni-margin-wrap">
			<swiper class="swiper" circular indicator-dots="true" autoplay="true" interval=2000 duration=500>
			<!-- 	<swiper-item>
					<view class="swiper-item">
						<image src="../../static/image/03.jpg"></image>

					</view>
				</swiper-item> -->
				<swiper-item>
					<view class="swiper-item">
						<image src="../../static/image/02.jpg" @click="jinru()"></image>

					</view>
				</swiper-item>
				<!-- <swiper-item>
					<view class="swiper-item">
						<image src="../../static/image/01.jpg"></image>

					</view>
				</swiper-item> -->
				<!-- <swiper-item>
					<view class="swiper-item">
						<image src="../../static/image/05.jpg"></image>

					</view>
				</swiper-item> -->
			</swiper>
		</view>
		<!-- <view class="enter"> -->
		<!-- 	<navigator url="/pages/message/message" open-type="switchTab" hover-class="other-navigator-hover"> -->
				<!-- <button type="primary" size="mini" @click="jinru()">登录</button> -->
			<!-- </navigator> -->
		<!-- </view> -->
	</view>
</template>

<script>
	export default {
		data() {
			return {

			}
		},
		methods: {
            jinru(){
				uni.redirectTo({
				           
				            url:'/pages/massage/massage'
				        });
			}
		}
	}
	
</script>

<style lang="scss">
	.swiper {
		height: 1550rpx;
	}

	.swiper-item {
		text-align: center;
		height: 100%; 

		image {
			width: 100%;
			height: 100%;
		}
	}

	.enter {
		position: absolute;
		top: 1000rpx;
		left: 320rpx;
	}
</style>
