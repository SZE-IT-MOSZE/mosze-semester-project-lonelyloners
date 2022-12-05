# CMake generated Testfile for 
# Source directory: D:/GitHub/mosze-semester-project-lonelyloners/pch/tests
# Build directory: D:/GitHub/mosze-semester-project-lonelyloners/pch/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(gametest "D:/GitHub/mosze-semester-project-lonelyloners/pch/build/tests/Debug/gametest.exe")
  set_tests_properties(gametest PROPERTIES  _BACKTRACE_TRIPLES "D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;16;add_test;D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(gametest "D:/GitHub/mosze-semester-project-lonelyloners/pch/build/tests/Release/gametest.exe")
  set_tests_properties(gametest PROPERTIES  _BACKTRACE_TRIPLES "D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;16;add_test;D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(gametest "D:/GitHub/mosze-semester-project-lonelyloners/pch/build/tests/MinSizeRel/gametest.exe")
  set_tests_properties(gametest PROPERTIES  _BACKTRACE_TRIPLES "D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;16;add_test;D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(gametest "D:/GitHub/mosze-semester-project-lonelyloners/pch/build/tests/RelWithDebInfo/gametest.exe")
  set_tests_properties(gametest PROPERTIES  _BACKTRACE_TRIPLES "D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;16;add_test;D:/GitHub/mosze-semester-project-lonelyloners/pch/tests/CMakeLists.txt;0;")
else()
  add_test(gametest NOT_AVAILABLE)
endif()
