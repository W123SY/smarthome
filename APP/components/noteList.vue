<template>
	<scroll-view scroll-x="true" style="white-space: nowrap;height: 180rpx;">
		<view class=" text" @click="enterDetail">
			<view>{{item.title}}</view>
			<view class="tesx">
				{{item.time}} {{item.content}}
			</view>
		</view>
		<button type="warn" size="mini" style="display: inline-block ;" @click="del">删除</button>
	</scroll-view>
</template>

<script>
	export default {
		name: "noteList",
		props: {
			item: Object,
			index: Number
		},
		data() {
			return {

			};
		},
		methods: {
			// 进入笔记详情页
			enterDetail() {
				this.$emit('enterDetail', this.index)
			},
			// 删除笔记
			del() {
				this.$emit('del', this.index)
			}
		}
	}
</script>

<style lang="less" scoped>
	.text {
		width: 70%;
		height: 100rpx;
		background-color: #fff;
		border-radius: 20rpx;
		padding: 20rpx;
		margin: 20rpx;
		border: 1px solid #000;
		display: inline-block;
	}

	.tesx {
		width: 100%;
		/*指定宽度*/
		white-space: nowrap;
		/*强制不换行*/
		text-overflow: ellipsis;
		/*溢出部分用省略号替代*/
		overflow: hidden;
		/*溢出隐藏*/
	}
</style>
