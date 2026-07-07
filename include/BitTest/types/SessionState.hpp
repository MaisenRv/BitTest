#pragma once
namespace BitTest::types{
    struct SessionState{
        private:
            int passed{};
            int failed{};
        public:
            void addPassed(){ passed++; }
            void addFailed(){ failed++; }

            int getPassed() const { return passed; }
            int getFailed() const { return failed; }
    };

    inline SessionState& getSessionState(){
        static SessionState session;
        return session;
    }
}