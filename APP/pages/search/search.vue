<template>
	<view>
		<!-- 笔记列表 -->
		<block v-for="(item,index) in productListRst" :key="index">
			<note-list :index="index" :item="item" @enterDetail="enterDetail" @del="del"></note-list>
		</block>
	</view>
</template>

<script>
	import noteList from '../../components/noteList.vue'
	export default {
		components: {
			noteList
		},
		data() {
			return {
				notes: {}, // 产品列表
				productListRst: {}, // 搜索筛选之后的产品列表
			}
		},
		onShow() {
			// 获取笔记列表数据
			this.getData()
		},
		methods: {
			// 获取笔记列表数据
			getData() {
				let data = JSON.parse(localStorage.getItem('notes'))
				this.notes = data
			},
			// 进入笔记详情页
			enterDetail(index) {
				let list = this.notes[index]

				uni.navigateTo({
					url: `../noteDetail/noteDetail?list=${JSON.stringify(list)}&index=${index}`
				})
			},
			// 删除笔记
			del(index) {
				let data = JSON.parse(localStorage.getItem('notes'))
				data.splice(index, 1)
				localStorage.setItem('notes', JSON.stringify(data))
				this.productListRst = data
			}
		},
		onNavigationBarSearchInputChanged(e) {
			let value = e.text
			// 若未输入值，则展示所有数据
			if (null === value || undefined === value) {
				this.productListRst = this.notes;
			} else {
				this.productListRst = []; // 结果列表置空
				let regStr = '';
				// 初始化正则表达式
				for (let i = 0; i < value.length; i++) {
					regStr = regStr + '(' + value[i] + ')([\\s]*)'; //跨字匹配
				}
				let reg = new RegExp(regStr);
				for (let i = 0; i < this.notes.length; i++) {
					let content = this.notes[i].content; //按照名字匹配
					let regMatch = content.match(reg);
					if (null !== regMatch) { // 将匹配的数据放入结果列表中
						this.productListRst.push(this.notes[i]);
					}
				}
			}
		}
	}
</script>

<style>
	/* 这是测试的第二篇文章 */
</style>
