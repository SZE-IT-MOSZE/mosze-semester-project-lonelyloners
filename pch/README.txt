Az ezen a linken:

https://drive.google.com/drive/folders/1yHYzBWvVwa4UhIxw97jf05H_C0vwvdyG?usp=share_link

elérhető "googletest" nevű mappát eme README.txt file MELLÉ ( ! ) szükséges bemásolni

+ build után a " build " nevű mappában("" nélkül) a " CMakeCache.txt "-t("" nélkül) tessék megynyitni
" CTRL+F " billentyűkombináció után tessék kimásolni ezt -> " gtest_force_shared_crt:BOOL=OFF "a macskakörmök nélkül ,
bemásolni a "Keresés" ablakba és megynyomni a "következő keresése" gombot.
Ha(1) nincs találat akkor a "build/teszt/Debug/gametest.exe"-vel le tudja futtatni a teszteket.
Ha(2) van találat akkor a találat sorának végén lévő "OFF" -ot át kell írni "ON" ra.
és valahogy így kell a sornak kinéznie:

gtest_force_shared_crt:BOOL=ON

ha ezeket a lépéseket elvégezte mentse el a CMakeCache.txt-t és ugyanúgy a "build/teszt/Debug/gametest.exe"
vel le tudja futtatni a teszteket.

Egyéb problémába ütközés esetén keresse a fejlesztőcsapatunkat.