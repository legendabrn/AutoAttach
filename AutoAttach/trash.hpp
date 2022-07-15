#pragma once

namespace config {
    bool status = false;
    std::string process{};
    std::uint32_t sleep{};
}

namespace cmd {
    bool status_command(int argc, char* argv[]) {
        if (argc < 2) {
            _plugin_logputs("[" PLUGIN_NAME "] Enter status(1/0)!");
            return false;
        }

        config::status = std::atoi(argv[1]);

        _plugin_logprintf("[" PLUGIN_NAME "] Set status: %d\n", config::status);
        return true;
    }

    bool set_command(int argc, char* argv[]) {
        if (argc < 2) {
            _plugin_logputs("[" PLUGIN_NAME "] Enter process name!");
            return false;
        }

        config::process = argv[1];

        _plugin_logprintf("[" PLUGIN_NAME "] Set process: %s\n", config::process.c_str());
        return true;
    }

    bool sleep_command(int argc, char* argv[]) {
        if (argc < 2) {
            _plugin_logputs("[" PLUGIN_NAME "] Enter sleep time(ms)!");
            return false;
        }

        config::sleep = std::atoi(argv[1]);

        _plugin_logprintf("[" PLUGIN_NAME "] Set sleep: %d ms\n", config::sleep);
        return true;
    }
}