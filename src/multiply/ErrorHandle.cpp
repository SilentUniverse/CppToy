#include <system_error>
#include <fmt/core.h>


enum class login_errc {
    success = 0,
    not_valid_pass,
    not_login,
};

inline std::error_code make_error_code(login_errc ec) {
	static const struct : public std::error_category {
		virtual std::string message(int val) const override {
			switch((login_errc)val) {
				case login_errc::success:
					return "登录成功";
				case login_errc::not_valid_pass:
					return "密码不对";
				case login_errc::not_login:
					return "用户未登录";
				default:
					return "未知错误";
			}
		}
		
		virtual const char *name() const noexcept override {
			return "login";
		}
	} category;
	return std::error_code((int)ec, category);
}


int sqrt(int x, std::error_code &ec) {
	if(x < 0){
			ec = make_error_code(std::errc::argument_out_of_domain);
		  return -1;
	}
	if(x == 3){
			ec = make_error_code(login_errc::not_valid_pass);
		  return -1;
	}
	if(x == 4){
			ec = make_error_code(login_errc::not_login);
		  return -1;
	}
	for(int i = 0;;i++) {
			if (i * i >= x) {
				return i;
			}
	} 
}
	
/*
std::variant<int, std::error_code> sqrt(int x) {
	if(x < 0){
			return make_error_code(std::errc::argument_out_of_domain);
	}
	if(x == 3){
			return = make_error_code(login_errc::not_valid_pass);
	}
	if(x == 4){
			return = make_error_code(login_errc::not_login);
	}
	for(int i = 0;;i++) {
			if (i * i >= x) {
					 return i;
			}
	}
}

int main() {
	auto ret = sqrt(4);
	fmt.println("variant类型结果 {}", ret.index());
	if (ret.index() == 0) {
		fmt.println("结果 {}", std::get<0>(ret));
	} else {
		fmt.println("出错 {}", std::get<1>(ret).message());
	}
	return 0;
}
*/


int main() {
	std::error_code ec;
	int ret = sqrt(4, ec);
	if(!ec){
		fmt::print("结果 {}", ret);
	} else {
		fmt::print("result出错了");
		std::string str = ec.message();
		fmt::print("出错原因 {}", str);
		if (ec == make_error_code(login_errc::not_login)) {
			fmt::print("跳转到登录页面");
		} else {
			exit(-1);
		}
	}
	return 0;
}

