#ifndef Hour_h_
#define Hour_h_
using namespace std;
class Hour
{
  private:
  int hour, minuto;

  public:
  Hour();
  Hour(int,int);
  int getHour();
  int getMinutos();
  void muestra();
  void setHour(int);
  void setMinutos(int);
};

Hour::Hour()
{
  hour = 0;
  minuto = 0;
}
Hour::Hour(int HourP, int minP)
{
  hour = HourP;
  minuto = minP;
}
int Hour::getHour()
{
  return hour;
}
int Hour::getMinutos()
{
  return minuto;
}
void Hour::muestra()
{
  cout << hour << " : " << minuto << endl;
}
void Hour::setHour(int HourP)
{
  hour = HourP;
}
void Hour::setMinutos(int minP)
{
  minuto = minP;
}

#endif