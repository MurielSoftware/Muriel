#pragma once

namespace Redneck
{
	class InputStream
	{
	private:
		unsigned _currentPosition;
		string _source;
	public:
		InputStream();
		InputStream(const string& path);
		virtual ~InputStream();

		char Peek();
		char Get();
		void Ignore();
		bool Eof();
	};
}