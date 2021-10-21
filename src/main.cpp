#include <armadillo>
#include "tests/testing.hpp"
#include "project3/config.hpp"
#include "project3/Particle.hpp"
#include "project3/PenningTrap.hpp"

using namespace std;
// TODO: V_0 and d only appears as V_0 / (d*d)

bool has_flag(const std::string& option, char** begin, char** end){
    return std::find(begin, end, option) != end;
}

void print_help_message() {
    cout << "Usage" << endl;
    cout << "\t./runner [flags]" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "\t-h\tShow this help message" << endl;
    cout << "\t-t\tRun all tests" << endl;
}

int main(int argc, char * argv[]) {
    arma::arma_rng::set_seed(42);

    if (has_flag("-h", argv, argv+argc)) print_help_message();
    if (has_flag("-t", argv, argv+argc)) run_testing();
    
    return 0;
    //example code with arbitrarily chosen values for
    //position and velocity

    // double charge, mass; charge = 1.0; mass = 2.0;
    // arma::vec pos = { 1.0, 0.0, 0.0 };
    // arma::vec vel = { 0.0, 1.0, 1.0 };

    Particle a(charge, mass, pos, vel);
    Particle b(2*charge, mass/2, -pos, -vel);

    PenningTrap pt(1 * 9.65e1, .0025 * 9.65e7, 500);
    pt.add_particle(a);
    pt.add_particle(b);

    //example of how to solve with RK4 and get solution/time
    pt.solve_RK4(10, 1e-2);
    std::vector<arma::mat> sol = pt.get_solution();
    std::vector<double> t = pt.get_time();
    //print solution in terminal
    for (int i = 0; i < 10; i++){
        sol[i].print();
        std::cout << std::endl;
    }
    return 0;
}
