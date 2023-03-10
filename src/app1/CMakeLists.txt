add_executable(app1 app1.cpp)
target_link_libraries(app1 PRIVATE fmt::fmt Pcap++)
# app1.cpp is from 

# copy .dll and .pcap after build
add_custom_command(TARGET app1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/dataset/IoT_Dataset_ServiceScan__00008_20180515135407.pcap" $<TARGET_FILE_DIR:app1>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:app1> $<TARGET_FILE_DIR:app1>
    COMMAND_EXPAND_LISTS
)