#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
using namespace eosio;

CONTRACT mocksystem : public contract {
   public:
      using contract::contract;

      ACTION buyram( const name& payer, const name& receiver, const asset& quant ){
         require_recipient(payer);
         require_recipient(receiver);
      }

      ACTION buyrambytes( const name& payer, const name& receiver, uint32_t bytes ){
         require_recipient(payer);
         require_recipient(receiver);
      }

      ACTION ramtransfer( const name& from, const name& to, int64_t bytes, const std::string& memo ){
         require_recipient(from);
         require_recipient(to);
      }

      ACTION transfer( const name& from, const name& to, asset quantity, const std::string& memo ){
         require_recipient(from);
         require_recipient(to);
      }
};