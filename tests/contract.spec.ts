const { Blockchain, expectToThrow } = require("@proton/vert");
const { assert } = require("chai");
const blockchain = new Blockchain()

// Load contract (use paths relative to the root of the project)
const eosio = blockchain.createContract('eosio', 'build/system')
const wram = blockchain.createContract('eosio.wram', 'build/contract')
const token = blockchain.createContract('eosio.token', 'build/token')
blockchain.createAccounts('noteosio')

/* Runs before each test */
beforeEach(async () => {
    blockchain.resetTables()
})

/* Tests */
describe('Test ram denier', () => {
    it('Should not be able to transfer RAM into the contract', async () => {
        expectToThrow(
            eosio.actions.buyram(['noteosio', 'eosio.wram', '1.0000 EOS']).send('noteosio@active'),
            'Cannot transfer RAM into this contract'
        )
        expectToThrow(
            eosio.actions.buyrambytes(['noteosio', 'eosio.wram', 1000]).send('noteosio@active'),
            'Cannot transfer RAM into this contract'
        )
        expectToThrow(
            eosio.actions.ramtransfer(['noteosio', 'eosio.wram', 1000, '']).send('noteosio@active'),
            'Cannot transfer RAM into this contract'
        )

        // Should not fail
        eosio.actions.buyram(['eosio', 'eosio.wram', '1.0000 EOS']).send('eosio@active')
        eosio.actions.buyrambytes(['eosio', 'eosio.wram', 1000]).send('eosio@active')
        eosio.actions.ramtransfer(['eosio', 'eosio.wram', 1000, '']).send('eosio@active')
    });
    it('Should not be able to transfer any tokens contract', async () => {
    
        expectToThrow(
            token.actions.transfer(['noteosio', 'eosio.wram', '1.0000 EOS', '']).send('noteosio@active'),
            'Cannot transfer tokens to this contract'
        )
        token.actions.transfer(['eosio', 'eosio.wram', '1.0000 EOS', '']).send('eosio@active')
    });
});
