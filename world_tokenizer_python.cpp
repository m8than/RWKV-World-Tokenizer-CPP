#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include "tokenizer.hpp" // Make sure this includes the correct path to your header

namespace py = pybind11;

PYBIND11_MODULE(world_tokenizer_cpp, m) {
    py::class_<TRIE, std::shared_ptr<TRIE>>(m, "TRIE")
        .def(py::init<>())
        .def("add", &TRIE::add)
        .def("find_longest_fast", &TRIE::find_longest);

    py::class_<TRIE_TOKENIZER, std::shared_ptr<TRIE_TOKENIZER>>(m, "TRIE_TOKENIZER")
        .def(py::init<const std::string&>())
        .def("encode", [](TRIE_TOKENIZER& self, const std::string& src) {
            try {
                return self.encode(src);
            } catch (const std::exception& e) {
                throw py::value_error(e.what());
            }
        })
        .def("encodeBatch", [](TRIE_TOKENIZER& self, const std::vector<std::string>& src) {
            try {
                return self.encodeBatch(src);
            } catch (const std::exception& e) {
                throw py::value_error(e.what());
            }
        })
        .def("decode", &TRIE_TOKENIZER::decode)
        .def("encodeBytes", &TRIE_TOKENIZER::encodeBytes)
        .def("decodeBytes", &TRIE_TOKENIZER::decodeBytes)
        .def("printTokens", &TRIE_TOKENIZER::printTokens);
}