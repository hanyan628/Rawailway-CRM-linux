/*******************************************************************
*
*    DESCRIPTION:Parameter Class
*
*    AUTHOR:HanYan
*
*    DATE:2010-3-29
*
*******************************************************************/
#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <tinyxml.h>
#include <string>
#include <map>
#include <algorithm>
#include <functional>


using namespace std;

//##ModelId=4CC7F9D4022F
class Parameter {
	public:
    //##ModelId=4CC7F9D402BA
		void Save();

		void ClearAllData()
		{
	    	_Param.clear();
		}

		const char* GetXMLFileName()
        {
            return XML_PARAMETER_FILE.c_str();
        }

    //##ModelId=4CC7F9D402BB
		const char* Get( const char* element, const char* key )
		{
			PARAM_LIST_TYPE::iterator p = _Param.find( element );
			if ( p == _Param.end() ) {
				return "";
			}
			PARAM_TYPE::iterator it = (*p).second.find( key );
			if ( it == (*p).second.end() ) {
				return "";
			}
			return (*it).second.c_str();
		};

    //##ModelId=4CC7F9D402BE
		void Set( const char* element, const char* key, const char* value )
		{
            Delete( element, key );
			_Param[element].insert(make_pair(key,value));
		};

    //##ModelId=4CC7F9D402C2
		void Delete( const char* element, const char* key = "all_key" )
		{
			if ( strcmp( key, "all_key") == 0 ) {
				_Param.erase( element );
			}

			PARAM_LIST_TYPE::iterator it = _Param.find( element );
			if ( it == _Param.end() ) {
				return;
			}

            (*it).second.erase( key );
		};

		void Reload()
		{
		    Reset();
		}

    //##ModelId=4CC7F9D402CA
		virtual ~Parameter()
		{
        	Save();
		};
    //##ModelId=4CC7F9D402CC
	friend Parameter& theParameter();
	private:
    //##ModelId=4CC7F9D402AA
		const string XML_PARAMETER_FILE;

    //##ModelId=4CC7F9D402CE
		Parameter():XML_PARAMETER_FILE("./parameter.xml")
		{
			Reset();
		};

    //##ModelId=4CC7F9D40230
		typedef map< const string, string > PARAM_TYPE;
    //##ModelId=4CC7F9D40232
		typedef map< const string, PARAM_TYPE > PARAM_LIST_TYPE;
    //##ModelId=4CC7F9D402AC
		PARAM_LIST_TYPE _Param;

    //##ModelId=4CC7F9D402CF
		void Reset();

    //##ModelId=4CC7F9D402D0
		void FillParam(PARAM_TYPE& param, TiXmlElement* root);

    //##ModelId=4CC7F9D40234
		class _FillElement {
		public:
        //##ModelId=4CC7F9D4029F
			_FillElement(TiXmlElement* el)
			:_element(el)
			{

			}

        //##ModelId=4CC7F9D402A1
			void operator()( pair< const string, PARAM_TYPE > &p )
			{
				TiXmlElement* el = new TiXmlElement(p.first);
				for_each( p.second.begin(), p.second.end(), _fill(el) );
				_element->LinkEndChild(el);
			}

		private:
        //##ModelId=4CC7F9D4029E
			TiXmlElement* _element;

        //##ModelId=4CC7F9D40235
			class _fill
			{
			public:
            //##ModelId=4CC7F9D4028B
				_fill(TiXmlElement* el):_element(el)
				{

				};

            //##ModelId=4CC7F9D4029C
				void operator()( pair< const string, string > &p )
				{
					TiXmlElement* el = new TiXmlElement(p.first);
					el->SetAttribute( "value", p.second );
					_element->LinkEndChild(el);
                }
			private:
            //##ModelId=4CC7F9D4023D
				TiXmlElement* _element;
			};

		};
};

inline Parameter& theParameter()
{
	static Parameter p;
	return p;
}

#endif

