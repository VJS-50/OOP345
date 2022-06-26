#include <iostream>
#include <cstring>
using namespace std;
enum class ActivityType { Lecture, Homework, Research, Presentation, Study };
class Activity {
	const char* m_description = nullptr;
	ActivityType m_activity;
public:
	Activity();
	~Activity();
	Activity(const char* desc, ActivityType type);
	Activity(Activity& actv);
	Activity(Activity&& actv);
	size_t activityTimeDuration();
	size_t totalNoOfActivity();

	Activity& operator=(Activity& actv);
	Activity& operator=(Activity&& actv);
};

static size_t activities = 0u;
Activity::Activity(){
	activities++;
	
}
Activity::~Activity(){
	
	m_description = nullptr;
	activities--;
}
Activity::Activity(const char* desc, ActivityType type = ActivityType::Study){
	if(strlen(desc) >= 3){
		m_description = desc;
		cout << m_description << endl;
		}
	m_activity = type;
	activities++;
}

size_t Activity::activityTimeDuration(){
	size_t minutes = 0u;
	try{
		if(m_description == nullptr){
			throw m_description;
		}
	}
	catch(const char*){
		throw std::runtime_error("Invalid current instance!");
	}
	 switch(m_activity) {
		 
         case ActivityType::Lecture:
             minutes = 100;
             break;
          case ActivityType::Homework:
             minutes = 7200;
             break;
		 case ActivityType::Research:
             minutes = 150;
             break;
		 case ActivityType::Presentation:
             minutes = 30;
             break;
		 case ActivityType::Study:
             minutes = 180;
             break;
		 default:
			 minutes = 0;
			 break;
     }
	return minutes;
}
size_t Activity::totalNoOfActivity(){
	return activities;
}
Activity::Activity(Activity& actv) {
	*this = actv;
}
Activity::Activity(Activity&& actv) {
	*this = std::move(actv);
}
Activity& Activity::operator=(Activity& actv){
	m_description = nullptr;
	m_description = actv.m_description;
	m_activity = actv.m_activity;

	return *this;
}
Activity& Activity::operator=(Activity&& actv){
	m_description = nullptr;
	m_description = actv.m_description;
	m_activity = actv.m_activity;

	activities--;
	actv.m_description = nullptr;

	return *this;
}