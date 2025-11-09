#include <argparse/argparse.hpp>
#include <iostream>
#include <propagation/hello.hpp>

int main(int argc, char *argv[]) {
    // top-level command parser
    argparse::ArgumentParser program("procli");

    // add subcommand paresr
    argparse::ArgumentParser add_command("add");
    add_command.add_description("Add file contents to the index");
    add_command.add_argument("files")
        .help("Files to add content from. Fileglobs can be given to add all matching files.")
        .remaining();

    // commit subcommand parser
    argparse::ArgumentParser commit_command("commit");
    commit_command.add_description("Record changes to the repository.");
    commit_command.add_argument("-a", "--all")
        .help("Tell the command to automatically stage files that have been modified and deleted.")
        .default_value(false)
        .implicit_value(true);
    commit_command.add_argument("-m", "--message")
        .help("Use the given <msg> as the commit message.");


    // add subparers to the main parser
    program.add_subparser(add_command);
    program.add_subparser(commit_command);


    try {
        program.parse_args(argc, argv);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    return 0;
}
