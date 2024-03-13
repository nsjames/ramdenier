#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
using namespace eosio;

CONTRACT ramdenier : public contract {
   public:
      using contract::contract;

      [[eosio::on_notify("eosio::buyram")]]
      void handle_buyram( const name& payer, const name& receiver, const asset& quant ){
         check(payer == name("eosio") && receiver == get_self(), "Cannot transfer RAM into this contract");
      }


      [[eosio::on_notify("eosio::buyrambytes")]]
      void handle_buyrambytes( const name& payer, const name& receiver, uint32_t bytes ){
         check(payer == name("eosio") && receiver == get_self(), "Cannot transfer RAM into this contract");
      }

      [[eosio::on_notify("eosio::ramtransfer")]]
      void handle_ramtransfer( const name& from, const name& to, int64_t bytes, const std::string& memo ){
         check(from == name("eosio") && to == get_self(), "Cannot transfer RAM into this contract");
      }

      [[eosio::on_notify("*::transfer")]]
      void handle_transfer( const name& from, const name& to, asset quantity, const std::string& memo ){
         check(to == get_self(), "Cannot transfer tokens into this contract");
      }

      ACTION empty(){}
};