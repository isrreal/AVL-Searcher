CPPFLAGS=-std=c++17 -Wall -Wextra -O3 
IPATH=-Iinc/
SRC=src/
OBJ=obj/

all: create_folder app

app: main.gch Person.gch PersonByCPF.gch PersonByName.gch PersonByBirthDate.gch  
	g++ $(OBJ)main.gch $(OBJ)Person.gch $(OBJ)PersonByCPF.gch $(OBJ)PersonByName.gch $(OBJ)PersonByBirthDate.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch
                                        
Person.gch: $(SRC)Person.cpp                         
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)Person.cpp -o $(OBJ)Person.gch

PersonByCPF.gch: $(SRC)PersonByCPF.cpp 
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)PersonByCPF.cpp -o $(OBJ)PersonByCPF.gch
	
PersonByName.gch: $(SRC)PersonByName.cpp 
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)PersonByName.cpp -o $(OBJ)PersonByName.gch
	
PersonByBirthDate.gch: $(SRC)PersonByBirthDate.cpp 
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)PersonByBirthDate.cpp -o $(OBJ)PersonByBirthDate.gch
	
create_folder:
	mkdir -p $(OBJ)
clean:
	rm -rf $(OBJ)*.gch

