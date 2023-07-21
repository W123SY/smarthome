//const BASE_URL = 'http://localhost:8000'
//const BASE_URL = 'http://192.168.124.17:8000'
const BASE_URL = 'https://www.yingcloud.com:8000'

export const myRequest = (options) => {
	const header_tmp = {
		"Authorization": "Bearer"+" "+uni.getStorageSync("Access_token") || ''
	};
	return new Promise((resolve,reject)=>{
		uni.request({
			url: BASE_URL+options.url,
			method:options.method || 'GET',
			data:options.data || {},
			header:header_tmp,
			success: (res) => {
				if(res.statusCode !== 200 && res.statusCode !== 201) {
					return uni.showToast({
						title:"请求失败"
					})
				};
				resolve(res)
			},
			fail: (err)=> {
				return uni.showToast({
					title:"请求接口失败"
				})
				reject(err)
			},
			
			
		})
	})
	
}
