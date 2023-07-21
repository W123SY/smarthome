<template>
	<view>
		<input v-model="title" placeholder="标题" style="font-size: 50rpx;">
		<view>{{time}}</view>
		<textarea v-model="content" style="width: 100%;"></textarea>
		<button @click="save" size="default" type="primary">保存</button>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				title: '',
				content: '',
				// time: '2月21日'
			}
		},
		methods: {
			save() {
				// 如果没有写内容的话，不能保存，进行提示
				if (this.content === '') {
					uni.showToast({
						title: '笔记内容为空',
						icon: "error"
					});
				} else {
					let notes = JSON.parse(localStorage.getItem('notes')) || []
					let obj = {
						'title': this.title,
						'time': this.time,
						'content': this.content
					}
					notes.push(obj)
					console.log('笔记列表为', notes);
					// 存入到缓存中
					localStorage.setItem('notes', JSON.stringify(notes))
					// 返回笔记列表页
					uni.switchTab({
						url: '../note/note'
					})
				}
			}
		}
	}
</script>

<style>

</style>
