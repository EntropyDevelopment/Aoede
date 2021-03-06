/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_SOUND_INC
#	define ENTROPY_AOEDE_SOUND_INC

#	include "Flac.hh"
#	include "Player.hh"
#	include "AL/Buffer.hh"
#	include <list>

	namespace Entropy
	{
		namespace Aoede
		{
			// 2017-08-03 AMR FIXME: don't depend on uv
			class Sound :
				public Tethys::UV::Task
			{
				public:
					explicit Sound(const std::string &);
					Sound(const std::string &, bool);
					virtual ~Sound();
					virtual void operator () ();
					virtual void Stop();
				protected:
					// 2017-08-03 AMR TODO: make interface more generic
					virtual void Added(Tethys::UV::Loop &);
				private:
					void DataCb(const Flac &, const std::int32_t *const []);
				private:
					Flac _data;
					Player _player;
					std::vector<AL::Source> _sources;
					std::list<AL::Buffer> _buffers;
					bool _looping;
					Tethys::UV::Loop *_loop;
					bool _playing;
					bool _done;
			};
		}
	}

#endif
