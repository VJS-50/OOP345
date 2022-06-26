namespace sdds{
	
	class Racecar:public Car{
		double m_booster;
	public:
		Racecar(std::istream& istr):Car(istr);	//set m_booster only
	};
	void display(std::ostream& ostr) const; //call Car::display();
	
	double topSpeed() const{return Car::topSpeed() * (1+m_booster)}
	
}