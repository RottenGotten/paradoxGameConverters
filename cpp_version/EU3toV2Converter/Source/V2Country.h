#ifndef V2COUNTRY_H_
#define V2COUNTRY_H_



#include "EU3Army.h"
#include "V2Inventions.h"
#include "Date.h"
#include <vector>
using namespace std;

class EU3World;
class EU3Country;
class V2World;
class V2State;
class V2Province;
class V2Relations;
class V2Army;
class V2Reforms;
class V2UncivReforms;
class V2Factory;
class V2Creditor;
class V2Leader;



class V2Country
{
	public:
		void								init(string tag, string countryFile, vector<int> parties, V2World* theWorld);
		void								initFromHistory();
		string							getTag() const;
		void								setSourceTag(string);
		void								addState(V2State*);
		void								setCapital(int);
		void								setCivilized(bool);
		bool								isCivilized();
		void								setPrimaryCulture(string);
		string							getPrimaryCulture() const;
		void								addAcceptedCulture(string);
		vector<string>					getAcceptedCultures();
		void								setReligion(string);
		string							getReligion();
		void								output(FILE*);
		string							getSourceTag();
		void								setPrestige(double);
		void								setLeadership(double);
		void								setArmyTech(double);
		void								setNavyTech(double);
		void								setCommerceTech(double);
		void								setIndustryTech(double);
		void								setCultureTech(double);
		void								setTechSchool(string);
		inventionStatus				getInventionState(inventionType);
		void								addPrestige(double);
		void								addPlurality(double);
		void								setGovernment(string);
		void								setUpperHouse(double reactionary, double conservative, double liberal);
		double							getReactionary();
		double							getConservative();
		double							getLiberal();
		vector< pair<int, int> >	getReactionaryIssues();
		vector< pair<int, int> >	getConservativeIssues();
		vector< pair<int, int> >	getLiberalIssues();
		void								setRulingParty();
		void								addRelations(V2Relations*);
		V2Relations*					getRelations(string);
		void								addArmy(V2Army*);
		V2Army*							getArmyForRemainder(RegimentCategory rc);
		void								setReforms(EU3Country*);
		void								setNationalIdea(EU3Country*, int& libertyLeft, int& equalityLeft);
		void								sortRelations(const vector<string>& order);
		bool								addFactory(V2Factory*);
		void								setMoney(double);
		void								setLastBankrupt(date);
		void								addLoan(string creditor, double size, double interest);
		void								setBankReserves(double);
		void								setDiploPoints(double);
		void								setBadboy(double);
		void								addLeader(V2Leader*);
		void								setupPops(EU3World& sourceWorld);
		void								setLiteracy(double);
		double							getLiteracy();
		void								addResearchPoints(double newPoints) { researchPoints += newPoints; };
		vector<V2State*>				getStates() const { return states; };
		int								getCapital() const { return capital; };
		void								addTech(string newTech) { techs.push_back(newTech); };
		vector<V2Province*>			getProvinces() const { return provinces; };
		void								setUncivReforms(V2UncivReforms* newReforms) { uncivReforms = newReforms; };
	private:
		void setIssues();
		void outputTech(FILE*);
		void outputInventions(FILE*);
		void outputElection(FILE*);
		void outputParties(FILE*);

		V2World*							theWorld;
		string							tag;
		vector<V2State*>				states;
		vector<V2Province*>			provinces;
		int								capital;
		bool								civilized;
		string							primaryCulture;
		vector<string>					acceptedCultures;
		string							religion;
		vector<int>						parties;
		int								rulingParty;
		string							sourceTag;
		string							countryFile;
		double							prestige;
		double							leadership;
		double							plurality;
		vector<string>					techs;
		inventionStatus				inventions[naval_exercises];
		V2UncivReforms*				uncivReforms;
		double							researchPoints;
		string							techSchool;
		string							government;
		double							upperHouseReactionary;
		double							upperHouseConservative;
		double							upperHouseLiberal;
		vector< pair<int, int> >	reactionaryIssues;
		vector< pair<int, int> >	conservativeIssues;
		vector< pair<int, int> >	liberalIssues;
		vector<V2Relations*>			relations;
		vector<V2Army*>				armies;
		V2Reforms*						reforms;
		string							nationalValue;
		double							money;
		date								lastBankrupt;
		map<string, V2Creditor*>	creditors;
		double							bankReserves;
		double							diploPoints;
		double							badboy;
		vector<V2Leader*>				leaders;
		double							literacy;
};


#endif	// V2COUNTRY_H_