
#include <cassert>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include "json11.hpp"
#include <list>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <type_traits>



using namespace json11;
using std::string;
string format_json(const char* type, const char* para)
{
	char buf[4096];
	sprintf(buf,R"({"type":"%s", "para":"%s"})",type,  para);
	return buf;
}
int main(void)
{
	const string simple_test = format_json("cmd","call_req");
//	simple_test.format(R"({"k1":"v1", "k2":42, "k3":["a",123,true,false,null]})";
	string err;
	const auto json = Json::parse(simple_test, err);
	
	std::cout << "type: " << json["type"].string_value() << "\n";
	std::cout << "para: " << json["para"].string_value() << "\n";

	const Json obj = Json::object({
		{"type","cmd"},
		{"para","call_hungup"},
	});
   	const auto json2 = Json::parse(obj.dump(), err);
	std::cout << "type: " << json2["type"].string_value() << "\n";
	std::cout << "para: " << json2["para"].string_value() << "\n";
}


