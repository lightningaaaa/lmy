1、
t_string::t_string(const std::string &o, const std::string &textdomain) : super(base(o, textdomain))
{
}

执行时转到了F:\MyCode_ShareVm\War-Of-Kingdom\kingdom-src\kingdom\librose\tstring.cpp:226
t_string_base::t_string_base(const std::string& string, const std::string& textdomain) :
	value_(1, ID_TRANSLATABLE_PART),
	translated_value_(),
	translation_timestamp_(0),
	translatable_(true),
	last_untranslatable_(false)
{
	if (string.empty()) {
		value_.clear();
		translatable_ = false;
		return;
	}

	std::map<std::string, unsigned int>::const_iterator idi = textdomain_to_id.find(textdomain);
	unsigned int id;

	if(idi == textdomain_to_id.end()) {
		id = id_to_textdomain.size();
		textdomain_to_id[textdomain] = id;
		id_to_textdomain.push_back(textdomain);
	} else {
		id = idi->second;
	}

	value_ += char(id & 0xff);
	value_ += char(id >> 8);
	value_ += string;
}