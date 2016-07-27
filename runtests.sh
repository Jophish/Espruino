rm profile
./espruino custom-tests/test_assignment.js
gprof espruino >> profile
cd ../CleanEspruino
rm profile
./espruino ../TestEspruino/custom-tests/test_assignment.js
gprof espruino >> profile
