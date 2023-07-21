<template>
	<view>
		<view>最近删除</view>
		<view class="work">
			<image src="@/static/images/noUpcoming.png" style="width: 100rpx;height: 100rpx;"></image>
			<view class="">没有待办</view>
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

		}
	}
</script>

<style lang="less" scoped>
	/* 主题颜色#1296db */
	.work {
		position: absolute;
		top: 50%;
		left: 50%;
		transform: translate(-50%, -50%);
	}

	select {
		border: none;
	}
</style>
