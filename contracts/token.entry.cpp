#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
using namespace eosio;

CONTRACT mocktoken : public contract {
   public:
      using contract::contract;

      ACTION transfer( const name& from, const name& to, asset quantity, const std::string& memo ){
         require_recipient(from);
         require_recipient(to);
      }
};