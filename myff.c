
#include "ffmpeg.h"
#include "libavdevice/avdevice.h"

int nb_output_files;
int nb_input_files;

int open_input_file() {
    int err, i, ret;
    const char *filename = "";
    InputFile *f;
    AVFormatContext *ic;
    AVInputFormat *file_iformat = NULL;
    const char *format = "h264";
    AVDictionary *options;
    av_dict_set(&options, "framerate", "30", 0);
    av_dict_set(&options, "video_size", "1920x1080", 0);

    ic = avformat_alloc_context();

    file_iformat = av_find_input_format(format);

    err = avformat_open_input(&ic, filename, file_iformat, &options);

    f = av_mallocz(sizeof(*f));
    input_files[nb_input_files - 1] = f;

    return 0;
}

int open_output_file()
{
    AVFormatContext *oc;
    int i, j, err;
    OutputFile *of;
    OutputStream *ost;
    InputStream *ist;
    AVDictionary *unused_opts = NULL;
    AVDictionaryEntry *e = NULL;
    int format_flags = 0;

    of = av_mallocz(sizeof(*of));
    output_files[nb_output_files - 1] = of;

    err = avformat_alloc_output_context2(&oc, NULL, "flv", "rtmp://xxxx");

    int qcr = avformat_query_codec(oc->oformat, AV_CODEC_ID_FLV1, 0);
}

static int transcode(void)
{
    int ret, i;
    AVFormatContext *os;
    OutputStream *ost;
    InputStream *ist;
    int64_t timer_start;
    int64_t total_packets_written = 0;


}

static void (*program_exit)(int ret);

void exit_program(int ret) {
    if (program_exit)
        program_exit(ret);

    exit(ret);
}




int main(int argc, char **argv) {

    return 0;
}

