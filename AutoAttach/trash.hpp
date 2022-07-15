#pragma once

namespace config {
    std::string process;
    bool status;
}

namespace cmd {
    bool set_command(int argc, char* argv[])
    {
        if (argc < 2) {
            _plugin_logputs("[" PLUGIN_NAME "] Enter process name!");
            return false;
        }

        config::process = argv[1];

        _plugin_logprintf("[" PLUGIN_NAME "] Set process: %s\n", config::process.c_str());
        return true;
    }

    bool status_command(int argc, char* argv[])
    {
        if (argc < 2) {
            _plugin_logputs("[" PLUGIN_NAME "] Enter status(1/0)!");
            return false;
        }

        config::status = atoi(argv[1]);

        _plugin_logprintf("[" PLUGIN_NAME "] Set status: %d\n", config::status);
        return true;
    }
}