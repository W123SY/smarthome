<template>
	<view>
		<view class="enter">
		<!-- 	<navigator url="/pages/message/message" open-type="switchTab" hover-class="other-navigator-hover"> -->
				<button type="primary"  @click="jinru()">登录</button>
			<!-- </navigator> -->
		</view>
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
				           
				            url:'/pages/device/device'
				        });
			}
		}
	}
</script>

<style>

</style>
