#include "coption.hpp"

COption::COption() : IOption()
{
	m_arg_list.clear();
}

COption::~COption() { }

bool COption::init(const int & argc, const char ** argv)
{
	if (argc == 1)
		return true;
	
	for (size_t i = 1; i < argc; i++)
	{
		std::string opt(argv[i]);
		auto p = isOption(opt);
		
		if (!p.first)
		{
			print(def::help);
			return false;
		}

		m_arg_list.push_back(p.second);
		
		if (m_arg_list.back().has_value)
		{
			i++;
			if (i >= argc)
			{
				print("Не указано значение для параметра " + 
						m_arg_list.back().name);
				print(def::help);
				return false;
			}
			
			opt = argv[i];
			auto pp = isOption(opt);

			if (pp.first)
			{
				print("Не указано значение для параметра " + 
						m_arg_list.back().name);
				print(def::help);
				return false;
			}

			m_arg_list.back().value = opt;
		}
	}

	return true;
}

std::pair<bool, option> COption::isOption(const std::string & opt)
{
	auto & args = def::arg_list;

	for (size_t i = 0; i < args.size(); i++)
		if (args[i].name == opt)
			return std::make_pair(true, args[i]);

	return std::make_pair(false, option());
}

int COption::getInt(const std::string & name, const int & def_val)
{
	std::string buf;
	for (auto & arg : m_arg_list)
		if (arg.name == name && arg.has_value)
			buf = arg.value;
	
	if (buf.empty())
		return def_val;

	return atoi(buf.data());
}

double COption::getDouble(const std::string & name, const double & def_val)
{
	std::string buf;
	for (auto & arg : m_arg_list)
		if (arg.name == name && arg.has_value)
			buf = arg.value;
	
	if (buf.empty())
		return def_val;

	return atof(buf.data());
}

std::string COption::getString(const std::string & name,
							   const std::string & def_val)
{
	std::string buf;
	for (auto & arg : m_arg_list)
		if (arg.name == name && arg.has_value)
			buf = arg.value;
	
	if (buf.empty())
		return def_val;

	return buf;
}

bool COption::needHelp()
{
	for (auto & arg : m_arg_list)
		if (arg.name == "--help")
		{
			print(def::help);
			return true;
		}
	return false;
}

void COption::print(const std::string & text)
{
	std::cout << "[COption] " << text << std::endl;
}

void COption::error(const std::string & text)
{
	print(text);
	print("Error №" + std::to_string(errno));
}