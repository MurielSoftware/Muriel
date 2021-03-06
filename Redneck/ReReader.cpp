#include "stdafx.h"
#include "ReReader.h"
#include <regex>

namespace Redneck
{
	bool Reader::IsDelimiter(string s)
	{
		return regex_match(s, regex("( |\\+|\\-|\\*|\\/|\\%|\\^|\\=| |\\n|\\r|\\t|\\(|\\)|\\{|\\}|\\;)"));
	}
}