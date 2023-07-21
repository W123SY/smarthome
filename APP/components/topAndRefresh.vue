<template>
  <view class="flex-column btns-wrap">
    <u-icon v-if="isToTop"
            name="arrow-upward"
            size="40"
            class="co-primary plr-8 ptb-8"
            @click="toTop"></u-icon>
    <view v-if="isRefresh" class="mid-line"></view>
    <u-icon v-if="isRefresh"
            name="reload"
            size="40"
            class="co-primary plr-8 ptb-8"
            @click="refresh"></u-icon>
  </view>
</template>
 
<script>
export default {
  props: {
    isToTop: { // 控制一键到顶按钮显隐
      type: Boolean,
      default: true
    },
    isRefresh: { // 控制一键刷新按钮显隐
      type: Boolean,
      default: true
    },
  },
  methods: {
    // 一键到顶，支持自定义duration
    toTop(duration) {
      uni.pageScrollTo({
        scrollTop: 0,
        duration: (duration === 0 || duration) ? duration : 500
      })
    },
// 一键刷新，传递事件给父组件
    refresh() {
      this.$emit('refresh');
    }
  },
}
</script>
<style lang="scss">
.btns-wrap {
  position: fixed;
  background: rgba(255, 255, 255, 0.8);
  border-radius: 60rpx;
  bottom: 200rpx;
  right: 60rpx;
  box-shadow: 0 0 4px 1px #f0f0f0;
  z-index: 998;
}
.mid-line {
  border-bottom: 2rpx solid #f0f0f0;
}
</style>