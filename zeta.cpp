#include <iostream>
#include "ezlib.h"
#include <fstream>



//Library ideas - it is a math library
///cnums
///number theory
///groups
///printing out of ALL OF THE things liek vectors
///matricies both dynamic and static
///Vectors (nuples)
///Plotting of stuffm gnuplot commands
///Maybe a way to handle functions (polynomials could work?)
///Fractions
///Going to need a documentation for all of this



int main(){
    
    unsigned resol = 10;
    std::vector<cnum> _M = mesh(-100,100,-100,100,resol);


    //std::cout << _M.size() << std::endl;
    
    //for(unsigned i=0; i<6; ++i){
    //    for(unsigned j=0; j<6; ++j)
    //        std::cout << _M[i*5+j] << "\t";
    //    std::cout << std::endl;
    //}
    
    
   //     std::ofstream dsave;
    //    dsave.open ("data.dat");
     //   for(unsigned i=0; i<_M.size(); ++i)
      //      dsave << _M[i].re() << "\t" << _M[i].im() << std::endl;
       // dsave.close();

    double q = 3;
    std::vector<cnum> results;

    
    /*
    ///2D Absolute Value Plot
    ///gnuplot cmd plot "data.dat" using 1:2:3 with image
    std::ofstream heat;
    heat.open ("data.dat");
    for(unsigned i=0; i<_M.size(); ++i){
        cnum res = _M[i].zg2(q);
        heat << _M[i].re() << "\t" << _M[i].im() << "\t" << log(res.abs()) << std::endl;
    }
    heat.close();
    */
    
    std::cout << fact(11).size() << "\t" << fact(8).size() << std::endl;
    /*
    std::ofstream heat;
    heat.open ("3d.dat");
    for(unsigned i=0; i<sqrt(_M.size()); ++i){
        for(unsigned j=0; j<sqrt(_M.size()); ++j){
        cnum res = _M[i].zgm(q);
            heat << _M[i*resol+j].re() << "\t" << _M[i*resol+j].im() << "\t" << res.re() << "\t" << res.im() << std::endl;}
            heat << std::endl;
            }
    heat.close();
     */
}