#include <string>
#include <memory>
#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>


void initializeLogger( const std::string& appName )
{
     static constexpr auto rotatingLogSize = 10u * 1024u * 1024u;
     static constexpr auto maxRotatingFiles = 10u;
     static constexpr auto rotateOnOpen = true;

     auto stderrSink = std::make_shared< spdlog::sinks::stderr_color_sink_mt >();
     stderrSink->set_level( spdlog::level::trace );
     stderrSink->set_pattern( "[multi_sink_example] [%^%l%$] %v" );

     auto rotatingFileSink = std::make_shared< spdlog::sinks::rotating_file_sink_mt >(
          appName + ".log"
          , rotatingLogSize
          , maxRotatingFiles
          , rotateOnOpen
          );
     rotatingFileSink->set_level( spdlog::level::trace );

     spdlog::set_default_logger(
          std::make_shared< spdlog::logger >(
               appName
               , spdlog::sinks_init_list{ stderrSink, rotatingFileSink }
               )
          );
}


int main()
{
     try
     {
          initializeLogger( "using-spdlog" );

          spdlog::info("Welcome to spdlog!");
          spdlog::error("Some error message with arg: {}", 1);

          spdlog::warn("Easy padding in numbers like {:08d}", 12);
          spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
          spdlog::info("Support for floats {:03.2f}", 1.23456);
          spdlog::info("Positional args are {1} {0}..", "too", "supported");
          spdlog::info("{:<30}", "left aligned");
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << e.what() << '\n';
          return 1;
     }
     return 0;
}
