#include<eosiolib/eosio.hpp>
#include<eosiolib/print.hpp>
#include<eosiolib/asset.hpp>
#include<eosiolib/dispatcher.hpp>
#include<string>
//#include<eosiolib/currency.hpp>
using namespace eosio;
using std::string;

class [[eosio::contract("deposite")]] testrecipient: public eosio::contract {
    
    public:
        using contract::contract;

        void transfer(name from,
                      name to,
                      asset        quantity,
                      string       memo ){
        
            for(int i=0;i < memo.length(); i++)
            {
                check(isdigit(memo[i]) != 0,"memo only is number");
            }
            check(memo.size() == 6,"length is illegle!");
//            int tag = std::stoi(memo);
//            printf("memo is %d\n",tag);
            check(std::stoi(memo) >= 106106,"memo should >= 106106");
        }
};

extern "C" {
   void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
        if (action == name("transfer").value){
        switch(action){
        EOSIO_DISPATCH_HELPER(testrecipient,(transfer));

        }
      }
   }
}
