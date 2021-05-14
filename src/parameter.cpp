#include "parameter.h"

//##ModelId=4CC7F9D402BA
void Parameter::Save()
{
	TiXmlDocument* pDoc = new TiXmlDocument( XML_PARAMETER_FILE );
	pDoc->LoadFile();
	TiXmlElement* element_root = pDoc->RootElement();
	if ( !element_root ) {
        TiXmlDeclaration* dec = new TiXmlDeclaration( "1.0", "UTF8", "" );
        pDoc->LinkEndChild( dec );

		element_root = new TiXmlElement( "root" );
		pDoc->LinkEndChild( element_root );
	}

	element_root->Clear();

	for_each( _Param.begin(), _Param.end(), _FillElement( element_root ) );

	pDoc->SaveFile();
	delete pDoc;
}

//##ModelId=4CC7F9D402CF
void Parameter::Reset()
{
	PARAM_TYPE param;

	_Param.clear();

	TiXmlDocument* pDoc = new TiXmlDocument( XML_PARAMETER_FILE );
	pDoc->LoadFile();

	TiXmlElement* element_root = pDoc->RootElement();
	if ( element_root ) {
		TiXmlElement* el = element_root->FirstChildElement();
		for ( ; el; el = el->NextSiblingElement() ) {
        	param.clear();
			string key = el->Value();
			FillParam( param, el );
			_Param[key] = param;
		}
	}

	delete pDoc;

}

//##ModelId=4CC7F9D402D0
void Parameter::FillParam(PARAM_TYPE& param, TiXmlElement* root)
{
	string key("");
	string value("");
	TiXmlElement* el = root->FirstChildElement();
	for ( ; el; el = el->NextSiblingElement() ) {
		key = el->Value();
		value = el->Attribute("value");
		param[key] = value;
	}
}

