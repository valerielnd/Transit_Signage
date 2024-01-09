CXX = g++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++14 -I/usr/local/include/gq

LDFLAGS = -L//home/val/western/cs3307/gumbo/gumbo-q2/gumbo-query/lib/
LDLIBS = -lcurl -lwthttp -lwt -lgq -lstdc++ -lm -pthread

SRCS = ../NewsAlert/Request2.cpp ../weather/Position.cpp ../weather/weather.cpp ../weather/ProcessOpenMeteo.cpp ../weather/ProcessOpenWeather.cpp \
       ../weather/OpenMeteoReq.cpp ../weather/OpenWeatherReq.cpp ../weather/WeatherData.cpp ../NewsAlert/NewsArticle.cpp ../NewsAlert/ProcessJSON.cpp \
       ../NewsAlert/ProcessHTML.cpp ../NewsAlert/NewsData.cpp ../NewsAlert/HTMLReq.cpp ../NewsAlert/JSONReq.cpp ../LTC/Service.cpp ../LTC/Bus.cpp ../LTC/BusStop.cpp \
       ../LTC/Passenger.cpp ../LTC/Schedule.cpp ../LTC/LTCAlert.cpp ../LTC/LTCInfo.cpp ../LTC/LTCStops.cpp ../LTC/LTCData.cpp Header.cpp \
       DateTimeSection.cpp LTCAlertAndInfoSection.cpp SignageSystem.cpp BusSection.cpp BusScheduleSection.cpp BusMapSection.cpp AppView.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

transit: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f transit $(OBJS)