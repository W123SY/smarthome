<template>
	<view class="">
		<input type="text" @value="tv" name="tv" v-model="textvalue.tv" />
		<button :type="buttonType" @click="changeTextValue()">按钮</button>
		<button :type="buttonType" @click="changeTextValue2()">按钮2</button>
	</view>
</template>z
<script>
var entry = { tv: null, av: null };
var app = getApp();
export default {
	data() {
		return {
			textvalue: entry,
			buttonType: 'primary',
			dem: null
		};
	},
	onLoad: function() {
	},
	methods: {
		changeTextValue() {
			let that = this;
			uni.request({
				url: 'http://121.36.11.13/PHPconnect.php',
				method: 'GET',
				data: {},
				success: function(res) {
					that.textvalue.tv = res.data.name;
				}
			});
		},
		changeTextValue2() {
			this.textvalue.tv=null;
		}
	}
};
</script>


<style>
	.content {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
	}

	.logo {
		height: 200rpx;
		width: 200rpx;
		margin-top: 200rpx;
		margin-left: auto;
		margin-right: auto;
		margin-bottom: 50rpx;
	}

	.text-area {
		display: flex;
		justify-content: center;
	}

	.title {
		font-size: 36rpx;
		color: #8f8f94;
	}
</style>
