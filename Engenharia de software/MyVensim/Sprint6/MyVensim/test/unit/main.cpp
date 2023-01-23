#include <iostream>
#include <string>
#include "unit_tests.h"
#include "unit_Stock.h"
#include "unit_Flow.h"
#include "unit_Model.h"

int main(){

        run_unit_tests_globals();

        run_unit_tests_Stock();

        run_unit_tests_Flow();

        run_unit_tests_Model();

        /* invoque outros metodos "void run_unit_tests_...(void)" aqui */

        return true;

}