#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;

int return_code = -1;

struct ReporterCounter: public ConsoleReporter {
    ReporterCounter(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            return_code = 0;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl;
            return_code = 1;
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

// int main(int argc, char** argv) {
//     /* See here https://github.com/onqtam/doctest/blob/master/doc/markdown/main.md for more options */
//     doctest::Context context;
//     context.addFilter("reporters", "console");   // options: "console", "xml", "empty", "grader"
//     //context.addFilter("reporters", "grader");   // options: "console", "xml", "empty", "grader"
//     context.run();  // returns 0 if all tests passed; otherwise returns 1.
// }
int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}
