
VPATH += ${BTSTACK_ROOT}/src
VPATH += ${BTSTACK_ROOT}/src/ble
VPATH += ${BTSTACK_ROOT}/src/ble/gatt-service
VPATH += ${BTSTACK_ROOT}/src/classic
VPATH += ${BTSTACK_ROOT}/example
VPATH += ${BTSTACK_ROOT}/3rd-party/bluedroid/decoder/srce
VPATH += ${BTSTACK_ROOT}/3rd-party/bluedroid/encoder/srce
VPATH += ${BTSTACK_ROOT}/3rd-party/hxcmod-player
VPATH += ${BTSTACK_ROOT}/3rd-party/hxcmod-player
VPATH += ${BTSTACK_ROOT}/3rd-party/hxcmod-player/mods
VPATH += ${BTSTACK_ROOT}/3rd-party/md5
VPATH += ${BTSTACK_ROOT}/3rd-party/micro-ecc
VPATH += ${BTSTACK_ROOT}/3rd-party/yxml

CFLAGS += -I.
CFLAGS += -I${BTSTACK_ROOT}/src/ble
CFLAGS += -I${BTSTACK_ROOT}/src/classic
CFLAGS += -I${BTSTACK_ROOT}/src
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/bluedroid/decoder/include
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/bluedroid/encoder/include
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/hxcmod-player
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/md5
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/micro-ecc
CFLAGS += -I${BTSTACK_ROOT}/3rd-party/yxml

# for CVSD/SBC PLC
LDFLAGS += -lm

CORE += \
	btstack_memory.c            \
	btstack_linked_list.c	    \
	btstack_memory_pool.c       \
	btstack_run_loop.c		    \
	btstack_util.c 	            \

COMMON += \
	ad_parser.c                 \
	hci.c			            \
	hci_cmd.c		            \
	hci_dump.c		            \
	l2cap.c			            \
	l2cap_signaling.c	        \
	btstack_audio.c             \
	btstack_tlv.c               \
	btstack_crypto.c            \
	uECC.c                      \
	sm.c                        \

CLASSIC += \
	btstack_link_key_db_memory.c   \
	sdp_util.c	                \
	spp_server.c  				\
	rfcomm.c	                \
	bnep.c	                    \
	sdp_server.c			            \
	device_id_server.c          \

SDP_CLIENT += \
	sdp_client.o		        \
	sdp_client_rfcomm.o		    \

ATT	+= \
	att_dispatch.c       	    \

GATT_SERVER += \
	att_db.c 				 	    \
	att_server.c        	    \

GATT_CLIENT += \
	gatt_client.c        	    \

PAN += \
	pan.c \

MBEDTLS = 					\
	bignum.c 				\
	ecp.c 					\
	ecp_curves.c 			\
	sm_mbedtls_allocator.c  \
	memory_buffer_alloc.c   \
	platform.c 				\

# List of files for Bluedroid SBC codec
include ${BTSTACK_ROOT}/3rd-party/bluedroid/decoder/Makefile.inc
include ${BTSTACK_ROOT}/3rd-party/bluedroid/encoder/Makefile.inc

SBC_DECODER += \
	btstack_sbc_plc.c \
	btstack_sbc_decoder_bluedroid.c \

SBC_ENCODER += \
	btstack_sbc_encoder_bluedroid.c \
	hfp_msbc.c \

CVSD_PLC = \
	btstack_cvsd_plc.c \

AVDTP += \
	avdtp_util.c  		\
	avdtp.c  			\
	avdtp_initiator.c 	\
	avdtp_acceptor.c  	\
	avdtp_source.c 		\
	avdtp_sink.c  		\
	a2dp_source.c 		\
	a2dp_sink.c  		\
	btstack_ring_buffer.c \

HXCMOD_PLAYER = \
	hxcmod.c 				    \
	nao-deceased_by_disease.c 	\

EXAMPLES = 					\
	audio_duplex 			\
	a2dp_sink_demo			\
	a2dp_source_demo        \
	ancs_client_demo		\
	att_delayed_response    \
	avrcp_browsing_client   \
	dut_mode_classic        \
	gap_dedicated_bonding	\
	gap_inquiry 			\
	gap_le_advertisements   \
	gap_link_keys           \
	gatt_battery_query      \
	gatt_browser            \
	gatt_heart_rate_client	\
	hfp_ag_demo             \
	hfp_hf_demo             \
	hid_host_demo           \
	hid_keyboard_demo 	    \
	hid_mouse_demo          \
	hog_keyboard_demo       \
	hog_mouse_demo          \
	hsp_ag_demo             \
	hsp_hs_demo             \
	le_counter              \
	le_data_channel_client  \
	le_data_channel_server  \
	le_streamer				\
	le_streamer_client      \
	led_counter				\
	mod_player	            \
	nordic_spp_le_counter   \
	nordic_spp_le_streamer  \
	pbap_client_demo		\
	sdp_bnep_query 			\
	sdp_general_query		\
	sdp_rfcomm_query		\
	sine_player             \
	sm_pairing_central      \
	sm_pairing_peripheral   \
	spp_and_le_counter 		\
	spp_and_le_streamer     \
	spp_counter 			\
	spp_streamer			\
	spp_streamer_client     \
	ublox_spp_le_counter    \

EXAMPLES_USING_LE =			\
	ancs_client_demo		\
	gap_le_advertisements   \
	gatt_battery_query      \
	gatt_browser			\
	hog_keyboard_demo       \
	hog_mouse_demo          \
	le_counter              \
	le_data_channel_client  \
	le_data_channel_server  \
	le_streamer				\
	le_streamer_client      \
	nordic_spp_le_counter   \
	nordic_spp_le_streamer  \
	sm_pairing_central      \
	sm_pairing_peripheral   \
	spp_and_le_counter	    \
	ublox_spp_le_counter    \

# .o for .c
CORE_OBJ    = $(CORE:.c=.o)
COMMON_OBJ  = $(COMMON:.c=.o)
CLASSIC_OBJ  = $(CLASSIC:.c=.o)
ATT_OBJ     = $(ATT:.c=.o)
GATT_CLIENT_OBJ = $(GATT_CLIENT:.c=.o)
GATT_SERVER_OBJ = $(GATT_SERVER:.c=.o)
PAN_OBJ = $(PAN:.c=.o)
SBC_DECODER_OBJ  = $(SBC_DECODER:.c=.o)
SBC_ENCODER_OBJ  = $(SBC_ENCODER:.c=.o)
CVSD_PLC_OBJ = $(CVSD_PLC:.c=.o)
AVDTP_OBJ  = $(AVDTP:.c=.o)
HXCMOD_PLAYER_OBJ = $(HXCMOD_PLAYER:.c=.o)

default_target: all

# compile .gatt descriptions
%.h: %.gatt
	python ${BTSTACK_ROOT}/tool/compile_gatt.py $< $@

# examples
ant_test: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ant_test.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

sdp_rfcomm_query: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${PAN_OBJ} ${SDP_CLIENT} sdp_rfcomm_query.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

pbap_client_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} md5.o obex_iterator.o obex_message_builder.o goep_client.o yxml.o pbap_client.o pbap_client_demo.o
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

sdp_general_query: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} sdp_general_query.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

sdp_bnep_query: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} sdp_bnep_query.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

spp_counter: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} spp_counter.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

le_counter: le_counter.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} battery_service_server.o le_counter.c
	${CC} $(filter-out le_counter.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

att_delayed_response: att_delayed_response.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} att_delayed_response.c
	${CC} $(filter-out att_delayed_response.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

hog_keyboard_demo: hog_keyboard_demo.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} battery_service_server.o device_information_service_server.o hids_device.o btstack_ring_buffer.o hog_keyboard_demo.c
	${CC} $(filter-out hog_keyboard_demo.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

hog_mouse_demo: hog_mouse_demo.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} battery_service_server.o device_information_service_server.o hids_device.o hog_mouse_demo.c
	${CC} $(filter-out hog_mouse_demo.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

sm_pairing_peripheral: sm_pairing_peripheral.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} sm_pairing_peripheral.c
	${CC} $(filter-out sm_pairing_peripheral.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

sm_pairing_central: sm_pairing_central.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} sm_pairing_central.o
	${CC} $(filter-out sm_pairing_central.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

le_streamer: le_streamer.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} le_streamer.c
	${CC} $(filter-out le_streamer.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

le_streamer_client: ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_CLIENT_OBJ} le_streamer_client.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gatt_heart_rate_client: ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_CLIENT_OBJ} gatt_heart_rate_client.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

spp_and_le_counter: spp_and_le_counter.h ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} spp_and_le_counter.c
	${CC} $(filter-out spp_and_le_counter.h,$^)  ${CFLAGS} ${LDFLAGS} -o $@

spp_and_le_streamer: spp_and_le_streamer.h ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} spp_and_le_streamer.c
	${CC} $(filter-out spp_and_le_streamer.h,$^)  ${CFLAGS} ${LDFLAGS} -o $@

spp_streamer: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} spp_streamer.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

spp_flowcontrol: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} spp_flowcontrol.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

spp_streamer_client: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} spp_streamer_client.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gap_dedicated_bonding: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} gap_dedicated_bonding.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gap_inquiry: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} gap_inquiry.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gap_link_keys: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} gap_link_keys.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

panu_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${PAN_OBJ} panu_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gatt_browser: gatt_browser.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_CLIENT_OBJ} ${GATT_SERVER_OBJ} gatt_browser.c
	${CC} $(filter-out gatt_browser.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

gatt_battery_query: gatt_battery_query.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_CLIENT_OBJ} ${GATT_SERVER_OBJ} gatt_battery_query.c
	${CC} $(filter-out gatt_battery_query.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

ancs_client_demo: ancs_client_demo.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} ${GATT_CLIENT_OBJ} ancs_client.c ancs_client_demo.c
	${CC} $(filter-out ancs_client_demo.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

led_counter: ${CORE_OBJ} ${COMMON_OBJ} led_counter.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

gap_le_advertisements: ${CORE_OBJ} ${COMMON_OBJ}  gap_le_advertisements.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hsp_hs_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_DECODER_OBJ} ${SBC_ENCODER_OBJ} ${CVSD_PLC_OBJ} wav_util.o sco_demo_util.o btstack_ring_buffer.o hsp_hs.o hsp_hs_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hsp_ag_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_DECODER_OBJ} ${SBC_ENCODER_OBJ} ${CVSD_PLC_OBJ} wav_util.o sco_demo_util.o btstack_ring_buffer.o hsp_ag.o hsp_ag_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hfp_ag_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_DECODER_OBJ} ${SBC_ENCODER_OBJ} ${CVSD_PLC_OBJ} wav_util.o sco_demo_util.o btstack_ring_buffer.o hfp.o hfp_gsm_model.o hfp_ag.o hfp_ag_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hfp_hf_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_DECODER_OBJ} ${SBC_ENCODER_OBJ} ${CVSD_PLC_OBJ} wav_util.o sco_demo_util.o btstack_ring_buffer.o hfp.o hfp_hf.o hfp_hf_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hid_host_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} btstack_hid_parser.o hid_host_demo.o
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hid_keyboard_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} btstack_ring_buffer.o hid_device.o btstack_hid_parser.o hid_keyboard_demo.o
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

hid_mouse_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} btstack_ring_buffer.o hid_device.o btstack_hid_parser.o hid_mouse_demo.o
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

a2dp_source_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_ENCODER_OBJ} ${AVDTP_OBJ} ${HXCMOD_PLAYER_OBJ} avrcp.o avrcp_controller.o avrcp_target.o a2dp_source_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

a2dp_sink_demo: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} ${SBC_DECODER_OBJ} ${AVDTP_OBJ} avrcp.o avrcp_controller.o avrcp_target.o btstack_resample.o a2dp_sink_demo.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

avrcp_browsing_client: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} ${SDP_CLIENT} avrcp.o avrcp_controller.o avrcp_browsing_controller.o avrcp_media_item_iterator.o avrcp_browsing_client.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

dut_mode_classic: ${CORE_OBJ} ${COMMON_OBJ} ${CLASSIC_OBJ} dut_mode_classic.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

le_data_channel_client: ${CORE_OBJ} ${COMMON_OBJ} le_data_channel_client.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

le_data_channel_server: le_data_channel_server.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} le_data_channel_server.c
	${CC} $(filter-out le_data_channel_server.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

mod_player: ${CORE_OBJ} ${COMMON_OBJ} ${HXCMOD_PLAYER_OBJ} btstack_audio.o mod_player.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

sine_player: ${CORE_OBJ} ${COMMON_OBJ} btstack_audio.o sine_player.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

audio_duplex: ${CORE_OBJ} ${COMMON_OBJ} btstack_audio.o btstack_ring_buffer.o audio_duplex.c
	${CC} $^ ${CFLAGS} ${LDFLAGS} -o $@

nordic_spp_le_counter: nordic_spp_le_counter.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} nordic_spp_service_server.o nordic_spp_le_counter.c
	${CC} $(filter-out nordic_spp_le_counter.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

nordic_spp_le_streamer: nordic_spp_le_streamer.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} nordic_spp_service_server.o nordic_spp_le_streamer.c
	${CC} $(filter-out nordic_spp_le_streamer.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

ublox_spp_le_counter: ublox_spp_le_counter.h ${CORE_OBJ} ${COMMON_OBJ} ${ATT_OBJ} ${GATT_SERVER_OBJ} device_information_service_server.o ublox_spp_service_server.o ublox_spp_le_counter.c
	${CC} $(filter-out ublox_spp_le_counter.h,$^) ${CFLAGS} ${LDFLAGS} -o $@

clean:
	rm -f ${EXAMPLES} *_demo
	rm -f  *.o *.out *.hex *.exe *.wav *.sbc
	rm -f  ancs_client_demo.h profile.h spp_and_le_counter.h le_counter.h le_streamer.h hog_keyboard_demo.h hog_mouse_demo.h
	rm -f  gatt_battery_query.h gatt_browser.h sm_pairing_peripheral.h spp_and_le_streamer.h 
	rm -f  le_data_channel_server.h sm_pairing_central.h
	rm -f  nordic_spp_le_counter.h nordic_spp_le_streamer.h nordic_spp_le_counter nordic_spp_le_streamer
	rm -f  ublox_spp_le_counter.h ublox_spp_le_counter 
	rm -f  le_streamer_and_counter_client.h le_streamer_and_counter_client
	rm -f  sco_output.msbc sco_input.msbc
	rm -rf *.dSYM
	rm -rf ${BTSTACK_ROOT}/src/*.o
	rm -rf ${BTSTACK_ROOT}/src/ble/*.o
	rm -rf ${BTSTACK_ROOT}/src/ble/gatt-service/*.o
	rm -rf ${BTSTACK_ROOT}/example/*.o
	rm -rf ${BTSTACK_ROOT}/example/ancs_client_demo.h
	rm -rf ${BTSTACK_ROOT}/example/profile.h
	rm -rf ${BTSTACK_ROOT}/example/spp_and_le_counter.h
	rm -rf ${BTSTACK_ROOT}/example/le_counter.h
	rm -rf ${BTSTACK_ROOT}/example/le_streamer.h
