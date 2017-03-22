#pragma once

namespace Redneck
{
	class InputStream
	{
	private:
		unsigned _currentPosition;
		string _source;
		
		bool IsTwoCharToken(string& current);
		bool ThisAndNextIs(const string& th, const string& ne);
	public:
		InputStream();
		InputStream(const string& path);
		virtual ~InputStream();

		string Peek();
		string Get();
		void Ignore();
		bool Eof();
		;
	};
}