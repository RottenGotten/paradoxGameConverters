#ifndef CK2PROVINCE_H_
#define CK2PROVINCE_H_


#include "..\Mappers.h"
#include <vector>
#include <map>
using namespace std;



class Object;
class CK2Title;
class CK2BuildingFactory;
class CK2Barony;

class CK2Province
{
	public:
		CK2Province(Object*, map<string, CK2Title*>, const CK2BuildingFactory* buildingFactory, const religionGroupMapping& religionGroupMap, const cultureGroupMapping& cultureGroupMap);

		int						getNumber()			const { return number; };
		vector<CK2Barony*>	getBaronies()		const { return baronies; };
		string					getCulture()		const { return culture; };
		string					getReligion()		const { return religion; };
		vector<double>			getTechLevels()	const { return techLevels; } ;
	private:
		int						number;
		vector<CK2Barony*>	baronies;
		string					culture;
		string					religion;
		vector<double>			techLevels;
};



#endif // CK2PROVINCE_H_